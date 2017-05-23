#include<iostream>  
using namespace std;  
  
#include<cstdlib>  
template<class K,class V>  
struct AVLTreeNode  
{  
    AVLTreeNode<K, V>* _left;  
    AVLTreeNode<K, V>* _right;  
    AVLTreeNode<K, V>* _parent;  
  
    K _key;  
    V _value;   
    int _bf;  
  
  
    AVLTreeNode(const K& key, const V& value)  
        :_left(NULL)  
        , _right(NULL)  
        , _parent(NULL)  
        , _bf(0)  
        , _key(key)  
        , _value(value)  
    {}  
};  
  
  
template<class K,class V>  
class AVLTree  
{  
    typedef AVLTreeNode<K, V> Node;  
public:  
    AVLTree()  
    :_root(NULL)  
    {}  
  
    ~AVLTree()  
    {}  
  
    bool Insert(const K& key, const V& value)  
    {  
        if (_root == NULL)  
        {  
            _root = new Node(key, value);  
            return true;  
        }  
  
        Node* parent = NULL;  
        Node* cur = _root;  
  
        //�жϲ����ֵ��cur�Ĵ�С  
        while (cur)  
        {  
            parent = cur;  
            if (cur->_key < key)  
            {  
                cur = cur->_right;  
            }  
            else if (cur->_key>key)  
            {  
                cur = cur->_left;  
            }  
            else  
            {  
                return false;  
            }  
        }  
  
        cur = new Node(key, value);//����һ���µĽڵ�  
        if (parent->_key > key)//������ڵ��ֵ����key,��key��Ϊ���ڵ�����  
        {  
            parent->_left = cur;  
            cur->_parent = parent;  
        }  
        else // ������ڵ��ֵС��key, ��key��Ϊ���ڵ���ұ�  
        {  
            parent->_right = cur;  
            cur->_parent = parent;  
        }  
  
        while (parent)  
        {  
            if (cur == parent->_left)//�������Ľڵ���parent����ߣ���ƽ������-1  
            {  
                parent->_bf--;  
            }  
            else//�������Ľڵ���parent���ұߣ���ƽ������+1  
            {  
                parent->_bf++;  
            }  
  
            if (parent->_bf == 0)//ƽ������Ϊ0�������ĸ߶�û�б仯  
            {  
                break;  
            }  
            else if(parent->_bf == -1 || parent->_bf == 1)  
            {  
                //�����ĸ߶ȱ仯�����Ǹ߶�û�б仯����������һ�������м�飬�Ƿ����һ����Ӱ��  
                cur = parent;  
                parent = cur->_parent;  
            }  
  
            else//�����ĸ߶�Ϊ2����-2 ���¶���������ƽ�⣬����Ҫ������ת  
            {  
                if(parent->_bf==2)//˵���ұ������ĸ߶�������  
                {  
                    Node* subR = parent->_right;  
  
                    if (subR->_bf == 1)  
                    {  
                        RotateL(parent);  
                    }  
                    else  
                    {  
                        RotateRL(parent);  
                    }  
                }  
  
                else//˵����ߵ������ĸ߶�������  
                {  
                    Node* subL = parent->_left;  
                    if (subL->_bf == -1)  
                    {  
                        RotateR(parent);  
                    }  
                    else  
                    {  
                        RotateLR(parent);  
                    }  
                }  
                break;  
            }  
        }  
    }  
  
    void InOrder()  
    {  
        _InOrder(_root);  
    }  
  
    bool IsBalance()  
    {  
        int height = 0;  
        return _IsBalance(_root,height);  
    }  
      
protected:  
    void RotateL(Node* parent)  
    {  
        Node* subR = parent->_right;  
        Node* subRL = subR->_left;  
        parent->_right = subRL;  
        if (subRL!=NULL)  
        {  
            subRL->_parent = parent;  
        }  
        subR->_left = parent;  
        Node* ppNode = parent->_parent;  
        parent->_parent = subR;  
        if (ppNode == NULL)  
        {  
            subR = _root;  
            subR->_parent = NULL;  
        }  
        else  
        {  
            if (ppNode->_left == parent)  
            {  
                ppNode->_left = subR;  
            }  
            else  
            {  
                ppNode->_right = subR;  
            }  
            subR->_parent = ppNode;  
        }  
        parent->_bf = subR->_bf = 0;  
    }  
  
    void RotateR(Node* parent)  
    {  
        Node* subL = parent->_left;  
        Node* subLR = subL->_right;  
  
        parent->_left = subLR;  
        if (subLR)  
        {  
            subLR->_parent = parent;  
        }  
        subL->_right = parent;  
        Node* ppNode = parent->_parent;  
        parent->_parent = subL;  
  
        if (ppNode == NULL)  
        {  
            _root = subL;  
            subL->_parent = NULL;  
        }  
        else  
        {  
            if (ppNode->_left == parent)  
            {  
                ppNode->_left = subL;  
            }  
            else  
            {  
                ppNode->_right = subL;  
            }  
            subL->_parent = ppNode;  
        }  
        parent->_bf = subL->_bf = 0;  
    }  
  
      
    void RotateLR(Node* parent)  
    {  
        Node* subL = parent->_left;  
        Node* subLR = subL->_right;  
        int bf = subLR->_bf;  
  
        RotateL(subL);  
        RotateR(parent);  
  
        if (bf == 0)  
        {  
            parent->_bf = subL->_bf = subLR->_bf = 0;  
        }  
        else if (bf==1)  
        {  
            subL->_bf = -1;  
            parent->_bf = 0;  
            subLR->_bf = 0;  
        }  
        else  
        {  
            subL->_bf = 0;  
            subLR->_bf = 0;  
            parent->_bf = 1;  
        }  
    }  
  
    void RotateRL(Node* parent)  
    {  
        Node* subR = parent->_right;  
        Node* subRL = subR->_left;  
        int bf = subRL->_bf;  
  
        RotateR(subR);  
        RotateL(parent);  
  
        if (bf == 0)  
        {  
            parent->_bf = subR->_bf = subRL->_bf = 0;  
        }  
        else if (bf == -1)  
        {  
            parent->_bf = 0;  
            subRL->_bf = 0;  
            subR->_bf = 1;  
        }  
        else  
        {  
            parent->_bf = -1;  
            subRL->_bf = 0;  
            subR->_bf = 0;  
        }  
    }  
  
    void _InOrder(Node* root)//����  
    {  
        if (root == NULL)  
        {  
            return;  
        }  
        _InOrder(root->_left);  
        cout << root->_key << ":" << root->_value << endl;  
        _InOrder(root->_right);  
    }  
  
    size_t _Height(Node* root)  
    {  
        if (root == NULL)  
        {  
            return 0;  
        }  
        size_t LHeight = _Height(root->_left);  
        size_t RHeight = _Height(root->_right);  
  
        return LHeight < RHeight ? RHeight + 1 : LHeight + 1;  
    }  
  
    bool _IsBalance(Node* root,int height)  
    {  
        if (root == NULL)  
        {  
            height = 0;  
            return true;  
        }  
        int l = 0;  
        int r = 0;  
  
        if (_IsBalance(root->_left, 1)&& _IsBalance(root->_right, r) && abs(r - 1) < 2)  
        {  
            height = l < r ? r + 1 : l + 1;  
  
            if (root->_bf != r - 1)  
            {  
                cout << "ƽ�������쳣"<<root->_key <<endl;  
                return false;  
            }  
            return true;  
        }  
    }  
  
protected:  
    Node* _root;  
};  
  
  
void Test()  
{  
    int a[10] = { 3, 2, 8, 1, 4, 13, 15, 7, 16, 14 };  
  
    AVLTree<int, int> tree;  
  
    for (int i = 0; i < 9; i++)  
    {  
        tree.Insert(a[i], i);  
    }  
    tree.InOrder();  
    tree.IsBalance();  
}  
  
  
int main()  
{  
    Test();  
    system("pause");  
    return 0;  
}  

