//求二叉树中的节点的个数以及第k层的节点的个数
#include<iostream>
using namespace std;
struct Node
{
	int _value;
	Node* _left;
	Node* _right;
};
//求二叉树的叶子节点的个数
size_t FindLeafSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	return FindLeafSize(root->_right) + FindLeafSize(root->_left);
}

//求第k层的节点个数
size_t FindKLeafSize(Node* root, size_t k, size_t level)
{
	static size_t num = 0;
	if (root == NULL)
	{
		return 0;
	}
	if (level == k)
	{
		++num;
		return num;
	}
	FindKLeafSize(root->_left, k, level + 1);
	FindKLeafSize(root->_right, k, level + 1);
	return num;
}