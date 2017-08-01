#include<iostream>
using namespace std;
#include<assert.h>
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
typedef TreeNode Node;
Node* ReBuild(int *preorder, int *inorder, int length)
{
	assert(preorder);
	assert(inorder);
	if (length <= 0)
	{
		return NULL;
	}
	Node* _root = new Node(*preorder);
	int *pre_tmp = preorder;
	int *in_tmp = inorder;
	int leftTreeNum = 0;
	int len = length;

	while (*in_tmp != *preorder)
	{
		leftTreeNum++;
		in_tmp++; 
		pre_tmp++;
		len--;

		if (len == 1 && *in_tmp != *preorder)
		{
			throw string("error");
		}
	}

	int* leftPreOrder = preorder + 1;
	int* rightPreOrder = pre_tmp + 1;
	int* leftOrder = inorder;
	int* rightOrder = in_tmp + 1;
	int rightTreeNum = length - leftTreeNum - 1;

	_root->_left = ReBuild(leftPreOrder, leftOrder, leftTreeNum);
	_root->_right = ReBuild(rightPreOrder, rightOrder, rightTreeNum);

	return _root;
}
