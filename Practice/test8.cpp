#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


//删除链表的非尾节点
void DeleteList(ListNode* node)
{
	if (node == NULL)
	{
		cout << "结点为空！" << endl;
	}
	else if (node->_next == NULL)
	{
		cout << "该结点是链表的尾结点！" << endl;
	}
	else
	{
		ListNode* del = node->_next;
		node->_value = del->_value;
		node->_next = del->_next;
		free(del);
		del = NULL;
	}
}

