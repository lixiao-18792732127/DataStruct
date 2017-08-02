//����ջʵ��һ������
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
		assert(!sin.empty() || sout.empty());//�ж���ջ��Ϊ�ջ��߳�ջΪ��
		if (sout.empty())//�����ջ����Ϊ��
		{
			while (!sin.empty())//��ջ���ֲ�Ϊ��
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

