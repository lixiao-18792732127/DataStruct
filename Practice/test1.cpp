//�ϲ�������������ʹ�úϲ����������Ȼ����
#include<iostream>
using namespace std;
struct ListNode
{
	int _value;//���������ֵ
	ListNode* _next;//��������ָ����һ���ڵ��ָ��
};
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == pHead2)//�������1��ͷ����������2��ͷ���
	{
		return pHead2;//��������2ͷ���
	}
	else if (pHead2 == NULL)//�������2��ͷ���Ϊ��
	{
		return pHead1;//ֱ�ӷ�������1��ͷ���
	}
	ListNode* pMergeHead = NULL;//����һ���ϲ����ͷ���
	if (pHead1->_value < pHead2->_value)//�������1��ͷ����ֵС������2��ͷ����ֵ
	{
		pMergeHead = pHead1;//�ϲ����ͷ����������1��ͷ���
		pMergeHead->_next = MergeList(pHead1->_next, pHead2);//ʹ�õݹ�ķ�������һ���ڵ�
	}
	else//�������1��ͷ����ֵ��������2��ͷ�ڵ��ֵ
	{
		pMergeHead = pHead2;//�ϲ����ͷ����������2��ͷ���
		pMergeHead->_next = MergeList(pHead1, pHead2->_next);//ʹ�õݹ�ķ�������һ���ڵ�
	}
	return;
}

