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

