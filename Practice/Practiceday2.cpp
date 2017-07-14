//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int _value;
//	ListNode* _next;
//};
//
////链表的逆置
//ListNode* ReverseList(ListNode* pHead)
//{
//	ListNode* pReversepHead = NULL;
//	ListNode* pNode = pHead;
//	ListNode* pPrev = NULL;
//	while (pNode != NULL)
//	{
//		ListNode* pNext = pNode->_next;
//		if (pNext == NULL)
//		{
//			pReversepHead = pHead;
//		}
//		pNext->_next = pPrev;
//		pPrev = pNode;
//		pNode = pNext;
//	}
//	return pReversepHead;
//
//}
//
////求链表中倒数第k个节点
////求倒数第k个节点，节点的下标是从0开始的，定义两个指针
////第一个指针先开始走,走到倒数第k-1个节点
////第二个节点开始向前走，等到第一个指针走到最后一个时，第二个指针刚好指向第k个节点
//ListNode* FindKthToTail(ListNode* pListNode, unsigned int k)
//{
//	if (pListNode == NULL || k == 0)
//	{
//		return NULL;
//	}
//	ListNode* pHead1 = pListNode;
//	ListNode* pHead2 = NULL;
//	for (unsigned int i = 0; i < k - 1; i++)
//	{
//		if (pHead1->_next != NULL)
//		{
//			pHead1 = pHead1->_next;
//		}
//		else
//		{
//			return NULL;
//		}
//	}
//	pHead2 = pListNode;
//	while (pHead1->_next != NULL)
//	{
//		pHead1 = pHead1->_next;
//		pHead2 = pHead2->_next;
//	}
//	return pHead2;
//}

#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum = 0;
	/*if (num2 == 0)
	{
		return num1;
	}
	sum = (num1 ^ num2);
	int num = (num1&num2) << 1;
	return Add(sum, num);*/
	sum = num1&num2;
	return sum;
}
int main()
{
	int m = 0;
	int n = 0;
	cout << "请输入要相加的两个数字->" << endl;
	cin >> m >> n;
	int ret = Add(m, n);
	cout << m << "和" << n << "想加的值为：" << ret << endl;
	system("pause");
	return 0;
}