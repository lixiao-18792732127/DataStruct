#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
//ц╟ещеепР
void BubbleSort(int *a, size_t n)
{
	int i, j;
	int tmp = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j <= n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
}
