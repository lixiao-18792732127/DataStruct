#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


// 求链表中倒数第k个节点
// 求倒数第k个节点，节点的下标是从0开始的，定义两个指针
// 第一个指针先开始走,走到倒数第k-1个节点
// 第二个节点开始向前走，等到第一个指针走到最后一个时，第二个指针刚好指向第k个节点
ListNode* FindKthToTail(ListNode* pListNode, unsigned int k)
{
	if (pListNode == NULL || k == 0)
	{
		return NULL;
	}
	ListNode* pHead1 = pListNode;
	ListNode* pHead2 = NULL;
	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pHead1->_next != NULL)
		{
			pHead1 = pHead1->_next;
		}
		else
		{
			return NULL;
		}
	}
	pHead2 = pListNode;
	while (pHead1->_next != NULL)
	{
		pHead1 = pHead1->_next;
		pHead2 = pHead2->_next;
	}
	return pHead2;
}

