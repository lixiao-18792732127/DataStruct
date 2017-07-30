#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* _next;
};


// �������е�����k���ڵ�
// ������k���ڵ㣬�ڵ���±��Ǵ�0��ʼ�ģ���������ָ��
// ��һ��ָ���ȿ�ʼ��,�ߵ�������k-1���ڵ�
// �ڶ����ڵ㿪ʼ��ǰ�ߣ��ȵ���һ��ָ���ߵ����һ��ʱ���ڶ���ָ��պ�ָ���k���ڵ�
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

