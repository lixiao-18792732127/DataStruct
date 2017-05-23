//MSD：由高位到个位，排低位时要排上一个位相同的元素（否则会影响上一个位的排序结果）
//LSD：由个位到高位
#include<iostream>
using namespace std;
#include<assert.h>
#pragma once

size_t GetMaxDigit(size_t *a, size_t n)
{
	size_t digit = 1;
	size_t base = 10;
	for (size_t i = 0; i < n; i++)
	{
		while (a[i] >= base)
		{
			base *= 10;
			digit++;
		}
	}
	return digit;
}


void LSDSort(size_t *a, size_t n)
{
	size_t maxDigit = GetMaxDigit(a, n);
	size_t base = 1;

	size_t *bucket = new size_t[n];
	while ((maxDigit--) > 0)
	{
		size_t counts[10] = { 0 };
		size_t start[10] = { 0 };
		start[0] = 0;

		for (size_t i = 0; i < n; i++)
		{
			size_t num = (a[i] / base) % 10;
			counts[num]++;
		}
		for (size_t i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + counts[i - 1];
		}

		for (size_t i = 0; i < n; i++)
		{
			size_t num = (a[i] / base) % 10;
			bucket[start[num]++] = a[i];
		}
		memcpy(a, bucket, sizeof(size_t)*n);
		base *= 10;
	}
}



void printArray(size_t *a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	size_t arr[] = { 1, 3, 5, 7, 0, 2, 9, 4, 6, 8 };
	//int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	size_t n = sizeof(arr) / sizeof(arr[0]);
	cout << "进行计数排序前：";
	printArray(arr, n);
	LSDSort(arr, n);
	cout << "进行计数排序后：";
	printArray(arr, n);
	system("pause");
	return 0;
}