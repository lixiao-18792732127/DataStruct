#include<iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
/*1,�ж�һ�Ŷ������Ƿ�Ϊƽ�������*/
int TreeDepth(TreeNode* _root)//ʹ�õݹ鷽������������ĸ߶�
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
	if (_root == NULL)//����Ҳ��ƽ�������
	{
		return true;
	}
	int left = TreeDepth(_root->_left);//
	int right = TreeDepth(_root->_right);
	if ((left - right) > 1 || (left - right) < -1)//ƽ����������ж����������������������ĸ߶Ȳ����1
	{
		//����߶Ȳ�ľ���ֵ����1�����ش���
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
		int diff = left - right;//����һ����ֵ������߼�ȥ�ұ�
		if (diff < 1 && diff >= -1)
		{
			Depth = 1 + (left>right ? left : right);
			return true;
		}
	}
	return false;
}
