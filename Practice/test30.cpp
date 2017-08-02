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

