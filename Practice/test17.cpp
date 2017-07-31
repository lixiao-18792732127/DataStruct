/*求二叉树中两个结点最近的公共祖先*/
#include<iostream>
using namespace std;
//是一棵搜索二叉树
struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode(int x)
		: _value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};
TreeNode* LowestAncestor(TreeNode* _root, TreeNode* node1, TreeNode* node2)
{
	int m1 = min(node1->_value, node2->_value);
	int m2 = max(node1->_value, node2->_value);
	while (true)
	{
		if (_root->_value > m2)
		{
			_root = _root->_left;
		}
		else if (_root->_value < m1)
		{
			_root = _root->_right;
		}
		else
		{
			break;
		}
	}
	return _root;
}

//三叉链二叉树
struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

	TreeNode(int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

TreeNode* LowestAncestor(TreeNode* _root, TreeNode* node1, TreeNode* node2)
{
	TreeNode* cur = NULL;
	while (node1 != NULL)
	{
		node1 = node1->_parent;
		cur = node2;
		while (cur != NULL)
		{
			if (node1 == cur->_parent)
			{
				return node1;
			}
			cur = cur->_parent;
		}
	}
}

//一般的二叉树
struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode(int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

TreeNode* LowestAncestor(TreeNode* _root, TreeNode* node1, TreeNode* node2)
{
	if (_root == NULL || _root == node1 || _root == node2)
	{
		return _root;
	}
	TreeNode* left = LowestAncestor(_root->_left, node1, node2);
	TreeNode* right = LowestAncestor(_root->_right, node1, node2);

	if (left != NULL&&right = !NULL)
	{
		return _root;
	}
	return left = NULL ? right : left;
}