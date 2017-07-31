#include<istream>
using namespace std;
struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
//判断一个节点是否在一颗二叉树中
bool DoesTreehaveNode(TreeNode* _root, int node)
{
	if (_root == NULL)
	{
		return false;
	}
	if (node < _root->_value)
	{
		DoesTreehaveNode(_root->_left, node);
	}
	else if (node>_root->_value)
	{
		DoesTreehaveNode(_root->_right, node);
	}
	else//node=_root->_value
	{
		return true;
	}
}