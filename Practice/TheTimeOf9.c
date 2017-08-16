#include<stdio.h>
#include<stdlib.h>]

int main()
{
	int n = 100;
	int num = 0;
	int i = 0;
	for ( i = 1; i < 100; i++)
	{
		if (i % 10 == 9)
		{
			num++;
		}
		if (i / 10 == 9)
		{
			num++;
		}
	}
	printf("1-100以内的数字出现9的次数为：%d\n", num);
	system("pause");
	return 0;
}