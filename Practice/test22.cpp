#include<iostream>
using namespace std;
#include<assert.h>

void SheelSort(int *a, size_t n)
{
	assert(a);
	int gub = n / 2;
	while (gub > 0)
	{
		for (size_t i = gub; i < n; i++)
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
