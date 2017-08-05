#include<iostream>
using namespace std;
#include<assert.h>

void _MergeSort(int* arr1, int* arr2, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(arr1, arr2, left, mid);
	_MergeSort(arr1, arr2, mid + 1, right);
	int begin1 = left;
	int begin2 = mid + 1;
	int index = 0;
	while (begin1 <= mid&&begin2 <= right)
	{
		if (arr1[begin1 <= mid&&begin2 <= right])
		{
			arr1[index++] = arr1[begin1++];
		}
		else
		{
			arr1[index++] = arr1[begin2++];
		}
	}
	while (begin1 <= mid)
	{
		arr2[index++] = arr2[begin1++];
	}
	while (begin2 < index)
	{
		arr2[index++] = arr2[begin2++];
	}
	int i = 0;
	int j = left;
	while (i < index)
	{
		arr1[j++] = arr2[i++];
	}
}

void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = new int[n];
	_MergeSort(a, tmp, 0, n - 1);
}