//删除小写字母字符串中出现重复的字符
#include<iostream>
using namespace std;
void DeleteCommonStr(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		int j = i + 1;
		int k = i + 1;
		while (a[k] != '\0')
		{
			if (a[k] != a[i])
			{
				a[j] = a[k];
				++j;
				++k;
			}
			else
			{
				++k;
			}
		}
		a[j] = '\0';
		++i;
	}
}
int main()
{
	char a[100];
	gets(a);
	DeleteCommonStr(a);
	cout << a << endl;
	system("pause");
	return 0;
}