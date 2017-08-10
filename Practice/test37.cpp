#include<iostream>
using namespace std;
#include<assert.h>
void *my_memmove(void *dst, const void *src, size_t count)
{
	assert(dst != NULL&&src != NULL);
	char* tdst = (char*)dst;
	char* tsrc = (char*)src;
	if (tdst <= tsrc || tdst >= tsrc + count)
	{
		while (count--)
		{
			*tdst++ = *tsrc++;
		}
	}
	else
	{
		tdst = tdst + count - 1;
		tsrc = tsrc + count - 1;
		while (count--)
		{
			*tdst -= *tsrc--;
		}
	}
	return dst;
}
int main()
{
	char a1[] = "hello world";
	my_memmove(a1 , a1, 9);
	cout << "result£º" << a1 << endl;
	char a2[] = "love you";
	my_memmove(a1, a2, 8);
	cout << "result£º" << a1 << endl;
	system("pause");
	return 0;
}