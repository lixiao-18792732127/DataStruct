#include<iostream>
using namespace std;
#include<stack>
typedef struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
}BinaryTreeNode, *BinaryTree;

/*�������*/
//1���ǵݹ鷽��
void PreOrder(BinaryTree _root)
{
	stack<BinaryTree> s;
	BinaryTree p = _root;
	while (p || !s.empty())
	{
		if (p != NULL)
		{
			s.push(p);
			cout << p->_value;
			p = p->_left;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->_right;
		}
	}
}
//2,�ݹ鷽��
void PreOrderR(BinaryTree _root)
{
	if (_root == NULL)
	{
		return;
	}
	cout << _root->_value << " ";
	PreOrderR(_root->_left);
	PreOrderR(_root->_right);
}

/*�������*/
//1���ǵݹ鷽��
void InOrder(BinaryTree _root)
{
	stack<BinaryTree> s;
	BinaryTree p = _root;
	while (p || !s.empty())
	{
		if (p != NULL)
		{
			s.push(p);
			p = p->_left;
		}
		else
		{
			p = s.top();
			cout << p->_value;
			s.pop();
			p = p->_right;
		}
	}
}
//�ݹ鷽��
void InOrderR(BinaryTree _root)
{
	if (_root == NULL)
	{
		return;
	}
	InOrderR(_root->_left);
	cout << _root->_value << " ";
	InOrderR(_root->_right);
}


/*�������*/
//1���ǵݹ鷽��
typedef struct BinaryTreeNodePost
{
	BinaryTree BTree;
	char tag;
}BinaryTreeNodePost,*BinaryTreePost;
void PostOrder(BinaryTree _root)
{
	stack<BinaryTreePost> s;
	BinaryTree p = _root;
	BinaryTreePost Bt;

	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			Bt = (BinaryTreePost)malloc(sizeof(BinaryTreePost));
			Bt->BTree = p;
			Bt->tag = 'L';
			s.push(Bt);
			p = p->_left;
		}
		while (!s.empty() && (s.top())->tag == 'R')
		{
			Bt = s.top();
			s.pop();
			Bt->BTree;
			cout << Bt->BTree->_value << " ";
		}
		if (!s.empty())
		{
			Bt = s.top();
			Bt->tag = 'R';
			p = Bt->BTree;
			p = p->_right;
		}
	}
}
//�ݹ鷽��
void PostOrderR(BinaryTree _root)
{
	if (_root == NULL)
	{
		return;
	}
	PostOrderR(_root->_left);
	PostOrderR(_root->_right);
	cout << _root->_value << " ";
}