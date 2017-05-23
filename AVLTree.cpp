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
  
        //判断插入的值和cur的大小  
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
  
        cur = new Node(key, value);//构建一个新的节点  
        if (parent->_key > key)//如果父节点的值大于key,则key就为父节点的左边  
        {  
            parent->_left = cur;  
            cur->_parent = parent;  
        }  
        else // 如果父节点的值小于key, 则key就为父节点的右边  
        {  
            parent->_right = cur;  
            cur->_parent = parent;  
        }  
  
        while (parent)  
        {  
            if (cur == parent->_left)//如果插入的节点在parent的左边，则平衡因子-1  
            {  
                parent->_bf--;  
            }  
            else//如果插入的节点在parent的右边，则平衡因子+1  
            {  
                parent->_bf++;  
            }  
  
            if (parent->_bf == 0)//平衡因子为0，子树的高度没有变化  
            {  
                break;  
            }  
            else if(parent->_bf == -1 || parent->_bf == 1)  
            {  
                //子树的高度变化，但是高度没有变化，继续向上一层树进行检查，是否对上一层有影响  
                cur = parent;  
                parent = cur->_parent;  
            }  
  
            else//子树的高度为2或者-2 导致二叉树不再平衡，则需要进行旋转  
            {  
                if(parent->_bf==2)//说明右边子树的高度增加了  
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
  
                else//说明左边的子树的高度增加了  
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
  
    void _InOrder(Node* root)//中序  
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
                cout << "平衡因子异常"<<root->_key <<endl;  
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

