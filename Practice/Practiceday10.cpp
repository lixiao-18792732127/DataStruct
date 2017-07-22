//��������еĽڵ�ĸ����Լ���k��Ľڵ�ĸ���
#include<iostream>
using namespace std;
struct Node
{
	int _value;
	Node* _left;
	Node* _right;
};
//���������Ҷ�ӽڵ�ĸ���
size_t FindLeafSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL&&root->_right == NULL)
	{
		return 1;
	}
	return FindLeafSize(root->_right) + FindLeafSize(root->_left);
}

//���k��Ľڵ����
size_t FindKLeafSize(Node* root, size_t k, size_t level)
{
	static size_t num = 0;
	if (root == NULL)
	{
		return 0;
	}
	if (level == k)
	{
		++num;
		return num;
	}
	FindKLeafSize(root->_left, k, level + 1);
	FindKLeafSize(root->_right, k, level + 1);
	return num;
}


//�ж�һ�������г���һ��������Ƕ���
#include<iostream>
using namespace std;

bool g_bInputInvalid = false;
bool CheacInvalidArr(int* num, int length)
{
	g_bInputInvalid = false;
	if (num == NULL&&length < 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}

bool CheackMoreThanHalf(int* num, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (num[i] == number)
		{
			times++;
		}
	}
	bool IsMreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		IsMreThanHalf = false;
	}
	return IsMreThanHalf;
}

int MoreThanHalfNum(int *num, int length)
{
	if (CheacInvalidArr(num, length))
	{
		return 0;
	}
	int result = num[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = num[i];
			times = 1;
		}
		else if (num[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if (!CheackMoreThanHalf(num, length, result))
	{
		result = 0;
	}
	return result;
}

int main()
{
	int arr[20] = { 0 };
	cout << "����������ĸ���->" << endl;
	int n = 0;
	cin >> n;
	cout << "�����������Ԫ��->" << endl;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int ret = MoreThanHalfNum(arr, n);
	cout << "��������һ�������Ϊ:" << ret << endl;
	system("pause");
	return 0;
}