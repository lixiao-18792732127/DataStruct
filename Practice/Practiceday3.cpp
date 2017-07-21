#include<iostream>
using namespace std;
typedef struct Node
{
	int _value;
	Node* _next;
}Node,*pNode;
/*带环问题，就是使用快慢指针的方法
定义两个指针，快指针和慢指针
快指针一次走两步，慢指针一次走一步
如果带环的话，快指针一定会遇到慢指针
*/
//判断是否为环
bool isCircle(pNode pHead)
{
	
	pNode fast = pHead;
	pNode slow = pHead;
	while (fast != NULL && fast->_next != NULL)
	{
		fast = fast->_next->_next;//快指针一次走两步
		slow = slow->_next;//慢指针一次走一步
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL || fast->_next == NULL)//如果快指针或者快指针的_next为空，则返回false
	{
		return false;
	}
	else
	{
		return true;
	}
}
//求出环的长度
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

//求环的入口点
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

