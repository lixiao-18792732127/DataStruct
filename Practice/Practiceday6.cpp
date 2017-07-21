//两个栈实现一个队列
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
template<typename T>
class Queue
{
public:
	void Push(const T& x)
	{
		sin.push(x);
	}
	void pop()
	{
		assert(!sin.empty() || sout.empty());//判断入栈不为空或者出栈为空
		if (sout.empty())//如果出栈数字为空
		{
			while (!sin.empty())//入栈数字不为空
			{
				sout.push(sin.pop());
				sin.pop();
			}
		}
		sout.pop();
	}
	const T& Front()
	{
		assert(!sin.empty() || sout.empty());
		if (sout.empty())
		{
			while(!sin.empty())
			{
				sout.push(sin.top());
				sin.pop();
			}
		}
		return sout.top();
	}
protected:
	stack<T> sin;
	stack<T> sout;
};

//两个队列实现一个栈
#include<iostream>
using namespace std;
#include<assert.h>
#include<queue>
template<typename T>
class Satck
{
public:
	void Push(const T& x)
	{
		qin.push(x);
	}
	void pop()
	{
		assert(!qin.empty() || qout.empty());
			if (qin.empty())
			{
				while (qout.size() > 1)
				{
					qin.push(qout.front());
					qout.pop();
				}
				qout.pop();
			}
			else
			{
				while (qin.size() > 1)
				{
					qout.push(qout.front());
					qin.pop();
				}
				qin.pop();
			}
	}
	T Top()
	{
		assert(!qin.empty() || !qout.empty());
		if (qin.empty())
		{
			while (qout.size() > 1)
			{
				qin.push(qout.front());
				qin.pop();
			}
			return qin.front();
		}
	}
protected:
	queue<T> qin;
	queue<T> qout;
};


#include<iostream>  
using namespace std;
#include<assert.h>  


void ReplaceBlank(char *arr)
{
	assert(arr);
	//先统计字符串的实际长度和空格的个数  
	int OldLen = 0;//定义数组的实际长度  
	int NewLen = 0;
	int BlankNum = 0;//定义计算数组中的空格的个数  
	int NewBack = 0;
	int OldBack = 0;



	while (arr[OldLen] != '\0')//当没有到字符串结尾处时，继续执行  
	{
		if (arr[OldLen] == ' ')//当遇到空格时，空格个数增加1；  
		{
			BlankNum++;
		}
		OldLen++;//只要数组没有到达结尾，length1就增加1  
	}

	NewLen = OldLen + BlankNum * 2;//替换空格后的数组的长度等于原来的长度+空格的长度乘以2  
	OldBack = OldLen - 1;
	NewBack = NewLen - 1;
	while (OldBack != 0)
	{
		if (arr[OldBack] == ' ')
		{
			arr[NewBack--] = '$';
			arr[NewBack--] = '$';
			arr[NewBack] = '$';
		}
		else
		{
			arr[NewBack] = arr[OldBack];
		}
		OldBack--;
		NewBack--;
	}
}

void PrintArr(char arr[])//打印数组的函数   
{
	int len = strlen(arr);
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		cout << arr[i];
	}
	cout << endl;
}

int main()
{
	char arr[50] = "talk is cheap show me the code";
	cout << "替换前的字符串：";
	PrintArr(arr);
	ReplaceBlank(arr);
	cout << "替换后的字符串：";
	PrintArr(arr);
	system("pause");
	return 0;
}