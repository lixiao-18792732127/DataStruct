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
	cout << "删除相同的字符串之后为："<<a << endl;
	system("pause");
	return 0;
}