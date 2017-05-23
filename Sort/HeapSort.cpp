#include<iostream>
using namespace std;
#include<assert.h>

void AdjustDown(int *a, size_t n, int root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a, size_t n)
{
	assert(a);
	int parent = (n - 2) >> 1;
	//建堆
	for (; parent >= 0; --parent)
	{
		AdjustDown(a, n, parent);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
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
	HeapSort(arr, n); 
	cout << "进行堆排序后：";
	printArray(arr, n);
	system("pause");
	return 0;
}