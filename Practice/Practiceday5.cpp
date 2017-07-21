#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


//ɾ����β���
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

//���������
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->_next;
		if (pNext == NULL)
		{
			pReverseHead = pHead;
		}
		pNext->_next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;

}