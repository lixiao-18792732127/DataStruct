#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum = 0;
	/*if (num2 == 0)
	{
		return num1;
	}
	sum = (num1 ^ num2);
	int num = (num1&num2) << 1;
	return Add(sum, num);*/
	sum = num1&num2;
	return sum;
}
int main()
{
	int m = 0;
	int n = 0;
	cout << "������Ҫ��ӵ���������->" << endl;
	cin >> m >> n;
	int ret = Add(m, n);
	cout << m << "��" << n << "��ӵ�ֵΪ��" << ret << endl;
	system("pause");
	return 0;
}
