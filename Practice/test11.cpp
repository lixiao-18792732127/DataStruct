#include <iostream>
using namespace std;

int calute(int num)
{
	int ret = 1;
	if (num <= 2)
	{
		return num;
	}
	while (num >= 2)
	{
		ret = ret*num;
		num = num - 1;
	}
	return ret;
}
int main()
{
	int num;
	int i;
	int count2 = 0, count5 = 0;
	cout << "������һ�����֡�>" << endl;
	cin >> num;
	for (i = 2; i <= num; i++)
	{
		int temp = i;
		while (temp % 2 == 0)
		{
			count2++;
			temp /= 2;
		}
		while (temp % 5 == 0)
		{
			count5++;
			temp /= 5;
		}
	}
	int res = count2>count5 ? count5 : count2;
	int ret = calute(num);
	cout << num << "�Ľ׳�֮��Ϊ:" << ret << "��" << ret << "��0�ĸ���Ϊ��" << res <<"��0��"<< endl;
	system("pause");
	return 0;
}



