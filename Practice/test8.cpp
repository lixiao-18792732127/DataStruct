#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


//ɾ������ķ�β�ڵ�
void DeleteList(ListNode* node)
{
	if (node == NULL)
	{
		cout << "���Ϊ�գ�" << endl;
	}
	else if (node->_next == NULL)
	{
		cout << "�ý���������β��㣡" << endl;
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

