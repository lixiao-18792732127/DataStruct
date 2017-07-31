//��������еĽڵ�ĸ����Լ���k��Ľڵ�ĸ���
#include<iostream>
using namespace std;
struct Node
{
	int _value;
	Node* _left;
	Node* _right;
};
//���������Ҷ�ӽڵ�ĸ���
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

//���k��Ľڵ����
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