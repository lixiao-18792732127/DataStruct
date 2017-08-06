//对n个数字进行右移k位
#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>
void Reverse(char* a, int left, int right)
{
	for (; left < right; left++, right--)
	{
		char tmp = a[right];
		a[right] = a[left];
		a[left] = tmp;
	}
}

int main()
{
	int k;
	char a[100];
	gets(a);
	int len = strlen(a);
	cout << "请输入k的值：" << endl;
	cin >> k;
	k = k / len;
	Reverse(a, 0,len - k - 1);
	Reverse(a, len - k, len - 1);
	Reverse(a, 0, len - 1);
	cout << a;
	system("pause");
	return 0;
}


