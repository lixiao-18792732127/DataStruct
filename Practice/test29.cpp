#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};

//Á´±íµÄÄæÖÃ
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversepHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->_next;
		if (pNext == NULL)
		{
			pReversepHead = pHead;
		}
		pNext->_next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversepHead;

}

