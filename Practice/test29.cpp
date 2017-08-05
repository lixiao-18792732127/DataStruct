#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int src[12] = { 7, 3, 7, 9, 2, 9, 1, 23, 5, 12, 34 };
	int dst[50];
	int i;
	memset(dst, 0, sizeof(dst));
	for (i = 0; i < 12; i++)
	{
		int data = src[i];
		dst[data]++;
	}
	for (i = 0; i < 50; i++)
	{
		while (dst[i]--)
		{
			cout << " " << i;
		}
	}
	cout << endl;
	system("pause");
	return 1;
}

