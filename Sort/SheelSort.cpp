#include<iostream>
using namespace std;
#include<assert.h>

void SheelSort(int *a, size_t n)
{
	assert(a);
	int gub = n / 2;//先定义增量为n/2
	while (gub > 0)
	{
		for (size_t i = gub; i < n; ++i)//从第gub个数据处开始进行交换
		{
			int tmp = a[i];
			int end = i - gub;
			while (end >= 0 && tmp < a[end])
			{
				a[end + gub] = a[end];
				end = end - gub;
			}
			a[end + gub] = tmp;
		}
		gub /= 2;
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
	SheelSort(arr, n);
	cout << "进行希尔排序前：";
	printArray(arr, n);
	cout << "进行希尔排序后：";
	printArray(arr, n);
	system("pause");
	return 0;
}