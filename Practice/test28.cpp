//快速排序之非递归实现
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
void QuickSort(int *a, size_t left, size_t right)
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