#include<iostream>
using namespace std;
#include<assert.h>

template<class K,size_t M = 3>
struct BTreeNode
{
	K _keys[M];
	BTreeNode<K, M> *_subs[M+1];
	BTreeNode<K, M> *_parent;
	size_t _size;//表示存储了多少个key值

	BTreeNode()
		:_size(0)
		, _parent(NULL)
	{
		memset(_subs, 0, sizeof(_subs));
		_parent = NULL;
		_size = 0;
		/*for (size_t i = 0; i <= M; ++i)
		{
			_subs[i] = NULL;
		}*/
	}
};

template<class K,class V,size_t M=3>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		:_root(NULL)
	{}

	pair<Node*, int> Find(const K& key)//查找一个数字
	{
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			size_t i = 0;
			for (; i < cur->_size;)
			{
				if (cur->_keys[i] < key)
				{
					++i;
				}
				else if (cur->_keys[i]>key)
				{
					break;
				}
				else
				{
					return make_pair(cur, i);
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair(parent, -1);
	}

	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_size = 1;
			return true;
		}

		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		Node* cur = ret.first;
		K newKey = key;
		Node* sub = NULL;
		while (1)
		{
			InsertKey(cur, sub, newKey);
			if (cur->_size < M)
			{
				return true;
			}
			//不满足规则分裂
			Node* newNode = new Node;
			size_t mid = M / 2;
			size_t i = mid + 1;
			size_t index = 0;
			for (; i < cur->_size; ++i)
			{
				newNode->_keys[index] = cur->_keys[i];
				newNode->_subs[index] = cur->_subs[i];
				++index;
				newNode->_size++;

				if (cur->_subs[i])
				{
					Node* sub = cur->_subs[i];
					cur->_subs[i] = NULL;
					sub->_parent = newNode;
				}
			}
			newNode->_subs[index] = cur->_subs[i];
			if (cur->_subs[i])
			{
				Node* sub = cur->_subs[i];
				cur->_subs[i] = NULL;
				sub->_parent = newNode;
			}
			cur->_size = (cur->_size) - (newNode->_size) - 1;


			if (cur->_parent == NULL)
			{
				_root = new Node;
				_root->_keys[0] = cur->_keys[mid];
				_root->_subs[0] = cur;
				cur->_parent = _root;
				_root->_subs[1] = newNode;
				newNode->_parent = _root;
				_root->_size++;
				return true;
			}
			else
			{
				newKey = cur->_keys[mid];
				cur = cur->_parent;
				sub = newNode;
			}
		}
	}

	
	void InsertKey(Node* cur, Node* sub, const K& key)
	{
		assert(cur);
		int end = (cur->_size) - 1;
		for (; end >= 0; --end)
		{
			if (cur->_keys[end] < key)
			{
				break;
			}
			else
			{
				cur->_keys[end + 1] = cur->_keys[end];
				cur->_subs[end + 2] = cur->_subs[end + 1];
			}
		}
		cur->_keys[end + 1] = key;
		cur->_subs[end + 2] = sub;
		if (sub)
		{
			sub->_parent = cur;
		}
		cur->_size++;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		size_t i = 0;
		for (; i < root->_size; ++i)
		{
			_InOrder(root->_subs[i]);
			cout << root->_keys[i] << " ";
		}
		_InOrder(root->_subs[i]);
	}

	
protected:
	Node* _root;
};

void TestBTree()
{
	BTree<int, int> t;
	int a[] = { 34, 67, 88, 32, 90, 25, 19 };
	cout << "B树进行插入后：" << "";
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		t.Insert(a[i]);
	}
	t.InOrder();
}

int main()
{
	TestBTree();
	system("pause");
	return 0;
}