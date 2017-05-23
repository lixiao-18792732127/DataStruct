#pragma once
#include<stack>
#include<queue>
#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	T _data;

	BinaryTreeNode(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(T* a, size_t n, const T& invalid = T())//构造函数
	{
		size_t index = 0;
		_root = _CreateTree(a, n, invalid, index);
	}

	~BinaryTree()//析构函数
	{
		_Destroy(_root);
	}

	BinaryTree(const BinaryTree<T>& t)//拷贝构造函数
	{
		_root = Copy(t._root);
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& t)//赋值运算符重载，传统写法
	{
		if (this != &t)
		{
			Node *newRoot = Copy(t._root);
			_Destroy(_root);
			_root = newRoot;
		}
	}

	void PrevOrder()//前序遍历
	{
		_PrevOrder(_root);
	}
	void PrevOrderR()
	{
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			Node* top = s.top();
			s.pop();
			cur = top->_right;
		}
		cout << endl;
	}
	void InOrder()//中序遍历
	{
		_InOrder(_root);
	}
	void InOrderR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			cout << top->_data << " ";
			s.pop();
			cout = top->_right;
		}
		cout << endl;
	}
	void PostOrder()//后序遍历
	{
		_PostOrder(_root);
	}
	void PostOrderR()
	{
		stack<Node*> s;
		Node* prev = NULL;
		Node* cur = _root;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();

			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				prev = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}
	}
	void LevelOrder()//层序遍历
	{
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (!q.empty())
		{
			Node* front = q.front();
			cout << front->_data << " ";
			q.pop();
			if (front->_left)
			{
				q.push(front->_left);
			}
			if (front->_right)
			{
				q.push(front->_right);
			}
		}
		cout << endl;
	}

	size_t Size()
	{
		size_t count = 0;
		return _Size(_root, count);
	}
	size_t GetLeafSize()
	{
		size_t count = 0;
		_GetLeafSize(_root, count);
		return count;
	}
	size_t GetKLevelSize(size_t k)
	{
		assert(k > 0);
		return _GetLevelSize(_root, k);
	}

	size_t Depth()
	{
		return _Depth(_root);
	}
	Node* Find(const T& x)
	{
		return _Find(_root, x);
	}
protected:

	Node* _CreateTree(T* a/*数组*/, size_t n, const T& invalid/*数据*/, size_t& index)//创造树
	{
		Node* root = NULL;
		if (index < n&&a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
	void _Destroy(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	Node* Copy(Node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		Node* newNode = new Node(root->_data);
		newNode->_left = Copy(root->_left);
		newNode->_right = Copy(root->_right);
		return newNode;
	}

	void _PrevOrder(Node* root)//前序
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)//中序
	{
		if (root == NULL)
		{
			return;
		_InOrder(root->_left);
		}
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)//后序
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}

	size_t _Size(Node* root, size_t& count)
	{
		if (root == NULL)
		{
			return 0;
		}
		count++;
		_Size(root->_left, count);
		_Size(root->_right, count);
	}
	size_t _GetLeafSize(Node* root, size_t& count)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->_left == NULL&&root->_right == NULL)
		{
			++count;
		}
		_GetLeafSize(root->_left, count);
		_GetLeafSize(root->_right, count);
	}

	size_t _GetLevelSize(Node* root, size_t k)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (k == 1)
		{
			return 1;
		}
		return _GetLevelSize(root->_left, k - 1) + _GetLevelSize(root->_right, k - 1);
	}

	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int left = _Depth(root->_left);
		int right = _Depth(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == x)
		{
			return root;
		}
		Node* ret = _Find(root->_left, x);
		if (ret)
		{
			return ret;
		}
		return _Find(root->_right, x);
	}
protected:
	Node* _root;
};

void Test()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	BinaryTree<int> t1(a, sizeof(a) / sizeof(a[0]), '#');
	cout << "前序遍历：";
	t1.PrevOrder();
	cout << endl<<"前序遍历：";
	t1.PrevOrderR();
	cout << "后序遍历：";
	t1.PostOrderR();
	cout << endl << "层序遍历：";
	t1.LevelOrder();

	cout << "Size:" << t1.Size() << endl;
	cout << "Leaf Size:" << t1.GetLeafSize() << endl;//叶子的数目
	cout << "K Level Size:" << t1.GetKLevelSize(3) << endl;//第K层的节点数目
	cout << "Depth:" << t1.Depth() << endl;

	cout << "查找节点4：" << t1.Find(4) << endl;
	cout << "查找节点8：" << t1.Find(8) << endl;

	BinaryTree<int> t2(t1);
	t2.InOrder();
	cout << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}