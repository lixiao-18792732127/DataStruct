#include<iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};

//��������ĸ߶�
int max(int x,int y)
{
	return x > y ? x : y;
}
void HighOfTree(TreeNode* _root, int &heigh)
{
	if (_root == NULL)
	{
		heigh = 0;
	}
	else
	{
		int heigh1, heigh2;
		HighOfTree(_root->_left, heigh1);
		HighOfTree(_root->_right, heigh2);
		heigh = max(heigh1, heigh2) + 1;
	}
}


//����һ�Ŷ�����

void Destroy(TreeNode* _root)
{
	if (_root)
	{
		Destroy(_root->_left);
		Destroy(_root->_right);
	}
	delete _root;
	_root == NULL;
}

#include<assert.h>

struct ListNode
{
	int _value;
	ListNode* _next;
};

ListNode* ReverseList(ListNode* pHead, int k)
{
	assert(k > 1);
}