#include<iostream>
using namespace std;
#include<assert.h>
#pragma once

void InsertSort(int *a, size_t n)//插入排序
{
	for (size_t i = 1; i < n; i++)
	{
		size_t j = 0;
		while (j < i&&a[j] <= a[i])
		{
			j++;
		}
		if (j < i)
		{
			size_t k = i;
			int tmp = a[i];
			while (k>j)
			{
				a[k] = a[k - 1];
				k--;
			}
			a[k] = tmp;
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
	//int arr[] = { 1, 3, 5, 7, 0, 2, 9, 4, 6, 8 };
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	cout << "进行插入排序后：";
	printArray(arr, n);
	system("pause");
	return 0;
}