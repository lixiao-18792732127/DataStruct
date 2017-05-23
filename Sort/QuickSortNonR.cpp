#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>


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

int GetMidIndex(int *a, int left, int right)//三数取中法
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
void QuickSortNonR(int *a, size_t left, size_t right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		if (end - begin < 30)
		{
			InsertSort(a + begin, end + begin + 1);
		}
		else
		{
			int div = PartSort3(a, begin, end);
			if ((div - 1)>begin)
			{
				s.push(div - 1);
				s.push(begin);
			}
			if ((div + 1) < end)
			{
				s.push(end);
				s.push(div + 1);
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
	int arr[] = { 1, 3, 6, 0, 8, 2, 9, 4, 7, 5 };
	/*int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };*/
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "进行快速排序非递归法前：";
	printArray(arr, n);
	cout << "进行快速排序非递归法后：";
	QuickSortNonR(arr, 0, n - 1);
	printArray(arr, n);
	system("pause");
	return 0;
}