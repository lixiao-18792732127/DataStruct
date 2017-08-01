#include<iostream>
using namespace std;
#include<assert.h>
void InsertSort(int* a, size_t n)
{
	for (int i = 1; i < n; i++)
	{
		int j = 0;
		while (j < i&&a[j] < a[i])
		{
			j++;
		}
		if (j < i)
		{
			int k = i;
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
