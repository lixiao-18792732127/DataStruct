#include<iostream>
using namespace std;
#include<stack>
#include<assert.h>
template<typename T>
class StackWithMin
{
public:
	void Push(const T& x)
	{
		s_Elem.push(data);
		if (s_Min.empty()||data<s_Min.top())
		{
			s_Min.push(data);
		}
		else
		{
			s_Min, push(s_Min.top());
		}
	}

	void pop()
	{
		assert(!s_Min.empty*() && !s_Elem());
		s_Min.pop();
		s_Elem.pop();
	}

	const T& Min() const
	{
		return s_Min.top();
	}
protected:
	stack<T> s_Elem;
	stack<T> s_Min;
};