#include<iostream>
using namespace std;
#include<assert.h>

int GetMidIndex(int *a, int left, int right)//三树取中法
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[left]>a[right])
		{
			return left;
		}
		else if (a[mid] > a[right])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}

int PartSort3(int *a, int left, int right)
{
	assert(a);
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);

	int prev = left - 1;
	int cur = left;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a[cur], a[prev]);
		}
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}

void QuickSort(int *a, size_t left, size_t right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
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
	int arr[] = { 1, 3, 6, 0, 8, 2, 9, 4, 7, 5 };
	/*int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };*/
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "进行快速排序后：";
	QuickSort(arr, 0, n - 1);
	printArray(arr, n);
	system("pause");
	return 0;
}