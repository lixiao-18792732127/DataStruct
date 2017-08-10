#include<iostream>
using namespace std;

void* my_memcpy(void* dst, const void* src, size_t count)
{
	if (dst == NULL || src == NULL)
	{
		return NULL;
	}
	unsigned char *pdst = (unsigned char*) dst;
	const unsigned char *psrc = (const unsigned char*) src;
	bool flag1 = (pdst >= psrc&&pdst < psrc + count);
	bool flag2 = (psrc >= pdst&&psrc < pdst + count);
	if (flag1 || flag2)
	{
		cout << "重叠" << endl;
		return NULL;
	}
	while (count--)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	return dst;
}

int main()
{
	char a1[] = "hello world";
	my_memcpy(a1 + 3, a1, 9);
	cout << "拷贝后的值：" << a1 << endl;
	char a2[] = "love you";
	my_memcpy(a1, a2, 8);
	cout << "拷贝后的值：" << a1 << endl;
	system("pause");
	return 0;
}