#include<iostream>
using namespace std;
#include<assert.h>
//—°‘Ò≈≈–Ú
void SelectSort(int *a, size_t n)
{
	assert(a);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		size_t MinIndex = left;
		size_t MaxIndex = right;
		for (size_t i = left; i <= right; i++)
		{
			if (a[i] < a[MinIndex])
			{
				MinIndex = i;
			}
			if (a[i]>a[MaxIndex])
			{
				MaxIndex = i;
			}
		}
		swap(a[left], a[MinIndex]);
		if (MaxIndex == left)
		{
			MaxIndex = MinIndex;
		}
		swap(a[right], a[MaxIndex]);
		++left;
		--right;
	}
}


