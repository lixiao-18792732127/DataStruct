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

//��������ʵ��һ��ջ
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
	//��ͳ���ַ�����ʵ�ʳ��ȺͿո�ĸ���  
	int OldLen = 0;//���������ʵ�ʳ���  
	int NewLen = 0;
	int BlankNum = 0;//������������еĿո�ĸ���  
	int NewBack = 0;
	int OldBack = 0;



	while (arr[OldLen] != '\0')//��û�е��ַ�����β��ʱ������ִ��  
	{
		if (arr[OldLen] == ' ')//�������ո�ʱ���ո��������1��  
		{
			BlankNum++;
		}
		OldLen++;//ֻҪ����û�е����β��length1������1  
	}

	NewLen = OldLen + BlankNum * 2;//�滻�ո�������ĳ��ȵ���ԭ���ĳ���+�ո�ĳ��ȳ���2  
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

void PrintArr(char arr[])//��ӡ����ĺ���   
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
	cout << "�滻ǰ���ַ�����";
	PrintArr(arr);
	ReplaceBlank(arr);
	cout << "�滻����ַ�����";
	PrintArr(arr);
	system("pause");
	return 0;
}