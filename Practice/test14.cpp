#include<iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
/*1,判断一颗二叉树是否为平衡二叉树*/
int TreeDepth(TreeNode* _root)//使用递归方法求出二叉树的高度
{
	if (_root == NULL)
	{
		return 0;
	}
	int left = TreeDepth(_root->_left);
	int right = TreeDepth(_root->_right);
	return (left > right) ? (left + 1) : (right + 1);
}
bool IsBalanceTree(TreeNode* _root)
{
	if (_root == NULL)//空树也是平衡二叉树
	{
		return true;
	}
	int left = TreeDepth(_root->_left);//
	int right = TreeDepth(_root->_right);
	if ((left - right) > 1 || (left - right) < -1)//平衡二叉树的判断条件，左子树与右子树的高度差不大于1
	{
		//如果高度差的绝对值大于1，返回错误
		return false;
	}
	else
	{
		return IsBalanceTree(_root->_left) && IsBalanceTree(_root->_right);
	}
}


bool IsBalanceTree(TreeNode* _root, int &Depth)
{
	if (_root == NULL)
	{
		Depth = 0;
		return true;
	}
	int left, right;
	if (IsBalanceTree(_root->_left, left) && IsBalanceTree(_root->_right, right))
	{
		int diff = left - right;//定义一个数值等于左边减去右边
		if (diff < 1 && diff >= -1)
		{
			Depth = 1 + (left>right ? left : right);
			return true;
		}
	}
	return false;
}
