#include<istream>
using namespace std;
struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
//�ж�һ���ڵ��Ƿ���һ�Ŷ�������
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