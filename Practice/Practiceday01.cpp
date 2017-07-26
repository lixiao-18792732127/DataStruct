//合并两个有序链表，使得合并后的链表依然有序
//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int _value;//定义链表的值
//	ListNode* _next;//定义链表指向下一个节点的指针
//};
//ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
//{
//	if (pHead1 == pHead2)//如果链表1的头结点等于链表2的头结点
//	{
//		return pHead2;//返回链表2头结点
//	}
//	else if (pHead2 == NULL)//如果链表2的头结点为空
//	{
//		return pHead1;//直接返回链表1的头结点
//	}
//	ListNode* pMergeHead = NULL;//定义一个合并后的头结点
//	if (pHead1->_value < pHead2->_value)//如果链表1的头结点的值小于链表2的头结点的值
//	{
//		pMergeHead = pHead1;//合并后的头结点等于链表1的头结点
//		pMergeHead->_next = MergeList(pHead1->_next, pHead2);//使用递归的方法到下一个节点
//	}
//	else//如果链表1的头结点的值大于链表2的头节点的值
//	{
//		pMergeHead = pHead2;//合并后的头结点等于链表2的头结点
//		pMergeHead->_next = MergeList(pHead1, pHead2->_next);//使用递归的方法到下一个节点
//	}
//	return;
//}
//计算1+2+3+...+n，不使用循环等。。
#include<iostream>
using namespace std;

class solute
{
public:
	int sum_solute(int n)
	{
		int res = n;
		res && (res += sum_solute(n - 1));
		return res;
	}
};

int main()
{
	solute s;
	int n = 0;
	cout << "请输入n的值" << endl;
	cin >> n;
	cout << "1加到" << n <<"的值为："<< s.sum_solute(n) << endl;
	system("pause");
	return 0;
}