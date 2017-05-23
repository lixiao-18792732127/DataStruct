#include<iostream>
using namespace std;
#include<assert.h>

int PartSort2(int *a, int left, int right)
{
	int key = a[right];//坑
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;

		}
		
		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			--right;

		}
		
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

void QuickSort(int *a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int div = PartSort2(a, left, right);
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
	int arr[] = { 1, 3, 0, 7, 8, 2, 9, 4, 6, 5 };

	/*int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };*/
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "进行快速排序前：";
	printArray(arr, n);
	cout << "进行快速排序后：";
	QuickSort(arr, 0, n-1);
	printArray(arr, n);
	system("pause");
	return 0;
}
