#include<iostream>  
using namespace std;  
  
#include<assert.h>  
  
template<class T>  
struct SearchBinaryTreeNode  
{  
    SearchBinaryTreeNode<T>* _left;  
    SearchBinaryTreeNode<T>* _right;  
  
    T _key;  
  
    SearchBinaryTreeNode(const T& k)  
        :_left(NULL)  
        ,_right(NULL)  
        ,_key(k)  
    {}  
};  
  
template<class T>  
class SearchBinaryTree  
{  
    typedef SearchBinaryTreeNode<T> Node;  
  
public:  
    SearchBinaryTree()  
        :_root(NULL)  
    {  
    }  
  
    ~SearchBinaryTree()  
    {  
        _Destory(_root);  
        _root = NULL;  
    }  
  
    //插入任意数字  
    bool Insert(const T& k)  
    {  
        if (_root == NULL)  
        {  
            return true;  
        }  
        Node* cur = _root;  
        Node* parent = cur;  
  
        while (cur)  
        {  
            parent = cur;  
            if (cur->_key < k)  
            {  
                cur = cur->_right;  
            }  
            else if (cur->_key>k)  
            {  
                cur = cur->_left;  
            }  
            else  
            {  
                return false;  
            }  
        }  
        if (parent->_key > k)  
        {  
            parent->_left = new Node(k);  
        }  
        else if (parent->_key < k)  
        {  
            parent->_right = new Node(K);  
        }  
        return true;  
    }  
  
    //查找任意数字  
    Node* Find(const T& k)  
    {  
        Node* cur = _root;  
        while (cur)  
        {  
            if (cur->_key > k)  
            {  
                cur = cur->_left;  
            }  
  
            else if (cur->_key < k)  
            {  
                cur = cur->_right;  
            }  
            else  
            {  
                return cur;  
            }  
        }  
        return NULL;  
    }  
  
  
  
    //删除一个节点  
    bool Remove(const T& k)  
    {  
        Node* cur = _root;  
        Node* parent = NULL;  
        Node* del = cur;  
  
  
        while (cur)  
        {  
            if (cur->_key < k)  
            {  
                parent = cur;  
                cur = cur->_right;  
            }  
            else if (cur->_key>k)  
            {  
                parent = cur;  
                cur = cur->_left;  
            }  
            else  
            {  
                break;  
            }  
        }  
        if (cur == NULL)  
        {  
            return false;  
        }  
        if (cur->_left == NULL)  
        {  
            del = cur;  
            if (cur == _root)  
            {  
                _root = cur->_right;  
            }  
            else if (cur == parent->_left)  
            {  
                parent->_left = cur->_right;  
            }  
            else  
            {  
                parent->_right = cur->_right;  
            }  
        }  
  
        else if (cur->_right == NULL)  
        {  
            del = cur;  
            if (cur == parent->_left)  
            {  
                _root = cur->_right;  
            }  
            else if (cur = parent->_right)  
            {  
                parent->_key = cur->_left;  
            }  
            else  
            {  
                parent->_right = cur->_right;  
            }  
        }  
  
        else  
        {  
            Node* subleft = NULL;  
  
            subleft = cur->_right;  
            parent = cur;  
            while (subleft->_left)  
            {  
                parent = cur;  
                subleft = subleft->_left;  
            }  
            cur->_key = subleft->_key;  
  
            if (parent->_left == subleft)  
            {  
                parent->_left = subleft->_right;  
            }  
            else if (parent->_right == subleft)  
            {  
                parent->_right = subleft->_right;  
            }  
            del = subleft;  
        }  
        delete del;  
        del = NULL;  
        return true;  
    }  
  
    //查找一个数字  
    Node* FindR(const T& k)  
    {  
        return _FindR(_root, k);  
    }  
    void InOrder()  
    {  
        _InOrder(_root);  
        cout << endl;  
    }  
    //插入一个数字  
    bool InsertR(const T& k)  
    {  
        return _InsertR(_root, k);  
    }  
      
    //删除一个数字  
    bool RemoveR(const T& k)  
    {  
        return _RemoveR(_root, k);  
    }  
  
protected:  
    //销毁  
    void _Destory(Node* root)  
    {  
        if (root == NULL)  
        {  
            return;  
        }  
        _Destory(root->_left);  
        _Destory(root->_right);  
    }  
  
    //查找  
    void _FindR(Node* root, const T& k)  
    {  
        if (root == NULL)  
        {  
            return NULL;  
        }  
        if (root->_key < k)  
        {  
            return _FindR(root->_right, k);  
        }  
        else if (root->_key > k)  
        {  
            return _FindR(root->_left, k);  
        }  
        else  
        {  
            return root;  
        }  
    }  
  
    //递归法插入一个数据  
    bool _InsertR(Node* root, const T& k)  
    {  
        if (root == NULL)  
        {  
            root = new Node(k);  
            return true;  
        }  
        if (root->_key > k)  
        {  
            return _InsertR(root->_left, k);  
        }  
        else if (root->_key < k)  
        {  
            return _InsertR(root->_right, k);  
        }  
        else  
        {  
            return false;  
        }  
    }  
  
    //删除一个数字  
    bool _RemoveR(Node* root, const T& k)  
    {  
        if (root == NULL)  
        {  
            return false;  
        }  
        Node* del = NULL;  
        if (root->_key < k)  
        {  
            return _RemoveR(root->_right, k);  
        }  
        else if (root->_key>k)  
        {  
            return _RemoveR(root->_right, k);  
        }  
        else  
        {  
            if (root->_left == NULL)  
            {  
                del = root;  
                root = root->_right;  
            }  
            else if (root->_right == NULL)  
            {  
                del = root;  
                root = root->_left;  
            }  
            else  
            {  
                Node* subleft = root->_right;  
                Node* parent = root;  
  
                while (subleft->_left)  
                {  
                    subleft = subleft->_left;  
                    parent = subleft;  
                }  
                if (parent->_left == subleft)  
                {  
                    parent->_left = subleft->_right;  
                }  
                else  
                {  
                    parent->_right = subleft->_right;  
                }  
                  
            }  
            delete del;  
            del = NULL;  
        }  
    }  
  
    void _InOrder(Node* root)  
    {  
        if (root == NULL)  
        {  
            return;  
        }  
        _InOrder(root->_left);  
        cout << root->_key << " ";  
        _InOrder(root->_right);  
    }  
  
protected:  
    Node* _root;  
};  
  
  
void Test()  
{  
    int arr[] = { 2, 4, 6, 8, 3, 5, 7, 9, 0 };  
    SearchBinaryTree<int> s;  
  
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)  
    {  
        s.InsertR(arr[i]);  
    }  
    s.InOrder();  
    s.RemoveR(4);  
    s.RemoveR(8);  
    s.RemoveR(10);  
    s.RemoveR(11);  
    s.RemoveR(15);  
  
    s.InOrder();  
  
    s.RemoveR(4);  
    s.RemoveR(5);  
    s.RemoveR(10);  
    s.RemoveR(11);  
    s.RemoveR(15);  
  
  
}  
  
int main()  
{  
    Test();  
    system("pause");  
    return 0;  
}  