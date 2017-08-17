#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	char arr1[100] = "######################";
	char arr2[] = "you are very beautiful";
	int len = sizeof(arr2) / sizeof(arr2[0])-2;
	printf("%s\n", arr1);
	int i = 0;
	for (i = 0; i <= len; i++, len--)
	{
		arr2[i] = arr1[i];
		arr2[len] = arr1[len];
		Sleep(1000);
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;
}