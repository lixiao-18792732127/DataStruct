//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int _value;
//	ListNode* _next;
//};
//
////���������
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
////�������е�����k���ڵ�
////������k���ڵ㣬�ڵ���±��Ǵ�0��ʼ�ģ���������ָ��
////��һ��ָ���ȿ�ʼ��,�ߵ�������k-1���ڵ�
////�ڶ����ڵ㿪ʼ��ǰ�ߣ��ȵ���һ��ָ���ߵ����һ��ʱ���ڶ���ָ��պ�ָ���k���ڵ�
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
	cout << "������Ҫ��ӵ���������->" << endl;
	cin >> m >> n;
	int ret = Add(m, n);
	cout << m << "��" << n << "��ӵ�ֵΪ��" << ret << endl;
	system("pause");
	return 0;
}