#include<iostream>
using namespace std;

struct Node
{
	int _value;
	Node* _left;
	Node* _right;
};

void Convert(Node* _root, Node*& prevNode)
{
	if (_root == NULL)
	{
		return;
	}
	Convert(_root->_left, prevNode);
	_root->_left = prevNode;
	if (prevNode)
	{
		prevNode->_right = _root;
	}
	prevNode = _root;
	Convert(_root->_right, prevNode);
}