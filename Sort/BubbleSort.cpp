#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
//Ã°ÅÝÅÅÐò
void BubbleSort(int *a, size_t n)
{
	int i, j;
	//int tmp = 0;
	for (i = n; i > 0 ; --i)
	{
		for (j = 1; j < i ; ++j)
		{
			if (a[j-1] < a[j ])
			{
				swap(a[j - 1], a[j]);
			}
		}
	}
}
void printArray(int *a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 1, 3, 5, 2, 0, 4, 9, 7, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "½øÐÐÃ°ÅÝÅÅÐòÇ°£º";
	printArray(arr, n);
	BubbleSort(arr, n);
	cout << "½øÐÐÃ°ÅÝÅÅÐòºó£º";
	printArray(arr, n);
	system("pause");
	return 0;
}