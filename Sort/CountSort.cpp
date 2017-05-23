//计数排序,只能对正整形排序 
//时间复杂度O(N+range);空间复杂度O(range)
#include<iostream>
using namespace std;
#include<assert.h>
#pragma once

void CountSort(int *a, size_t n)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (size_t i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int *Counts = new int[range];
	memset(Counts, 0, sizeof(size_t)*range);

	for (size_t i = 0; i < n; ++i)
	{
		Counts[a[i] - min]++;
	}
	size_t j = 0;

	for (size_t i = 0; i < n; ++i)
	{
		while (Counts[i]--)
		{
			a[j++] = i + min;
		}
	}
	delete[] Counts;
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
	int arr[] = { 1, 3, 5, 7, 0, 2, 9, 4, 6, 2 };
	//int arr[] = { 4, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, n);
	cout << "进行计数排序法后：";
	printArray(arr, n);
	system("pause");
	return 0;
}




