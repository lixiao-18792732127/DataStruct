//求一个数组的中位数
#include<iostream>
using namespace std;
#include<assert.h>
//使用快速排序的方法
int PartSort(int *a, int start, int end)
{
	int left = start;
	int right = end;
	int key = a[end];
	while (left < right)
	{
		while (left < right&&a[left] <= key)
		{
			++left;
		}
		while (left < right&&a[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			swap(a[left], a[right]);
		}
	}
	swap(a[right], a[end]);
	return left;
}
int GetMidNumSort(int* a, int size)
{
	assert(a);
	int start = 0;
	int end = size - 1;
	int mid = (size - 1) / 2;
	int div = PartSort(a, start, end);
	while (div != mid)
	{
		if (mid < div)
		{
			div = PartSort(a, start, div - 1);
		}
		else
		{
			div = PartSort(a, div + 1, end);
		}
	}
	return a[mid];
}


int main()
{
	int a[10] = { 2, 4, 1, 6, 7, 3, 8, 9, 2, 9 };
	int ret = GetMidNumSort(a, sizeof(a) / sizeof(a[0]));
	cout << ret << endl;
	system("pause");
	return 0;
}