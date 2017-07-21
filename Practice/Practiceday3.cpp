#include<iostream>
using namespace std;
typedef struct Node
{
	int _value;
	Node* _next;
}Node,*pNode;
/*�������⣬����ʹ�ÿ���ָ��ķ���
��������ָ�룬��ָ�����ָ��
��ָ��һ������������ָ��һ����һ��
��������Ļ�����ָ��һ����������ָ��
*/
//�ж��Ƿ�Ϊ��
bool isCircle(pNode pHead)
{
	
	pNode fast = pHead;
	pNode slow = pHead;
	while (fast != NULL && fast->_next != NULL)
	{
		fast = fast->_next->_next;//��ָ��һ��������
		slow = slow->_next;//��ָ��һ����һ��
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->_next == NULL)//�����ָ����߿�ָ���_nextΪ�գ��򷵻�false
	{
		return false;
	}
	else
	{
		return true;
	}
}
//������ĳ���
int CircleLength(pNode pHead)
{
	if (isCircle(pHead) == false)
	{
		return 0;
	}
	pNode fast = pHead;
	pNode slow = pHead;
	int length = 0;
	bool begin = false;
	bool again = false;
	while (fast != NULL && fast->_next != NULL)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow && again == true)
		{
			break;
		}
		if (fast == slow && again == false)
		{
			begin = true;
			again = true;
		}
		if (begin == true)
		{
			++length;
		}
	}
	return length;
}

//�󻷵���ڵ�
Node* findLoopEnterance(pNode pHead)
{
	pNode fast = pHead;
	pNode slow = pHead;
	while (fast != NULL || fast->_next != NULL)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->_next == NULL)
	{
		return NULL;
	}
	slow = pHead;
	while (slow != fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}

class AA
{
public:
	AA()
	{
	}
};
class BB:public AA
{

};

#include<iostream>
using namespace std;

class HeapType
{
public:
	static HeapType *Creat()
	{
		return new HeapType;
	}
private:
	HeapType()
	{
	}
	HeapType(const HeapType&);
	HeapType& operator=const HeapType;
	int _a;
};

int main()
{
	static HeapType ht1;
	HeapType ht2;
	HeapType* ht3 = new HeapType;
	HeapType* ht4 = HeapType::Creat();
	HeapType ht5(*ht4);
	StackType;
	return 0;
}

