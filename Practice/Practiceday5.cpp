#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


//删除非尾结点
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

//链表的逆置
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