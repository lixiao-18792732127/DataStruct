#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int num = 1;
	printf("请输入口诀的行列->\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d   ", j, i, i*j);
			
		}
		printf("\n");
	}

	system("pause");
	return 0;
}