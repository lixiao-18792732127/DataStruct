#include<iostream>
using namespace std;
int fun(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;
}
int main()
{
	cout<<"������һ������->";
	int num = 0;
	cin >> num;
	int ret = fun(num);
	cout << num << "�еĶ�����λ�е�1�ĸ���Ϊ��" << ret << endl;
	system("pause");
	return 0;
}