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
	cout<<"请输入一个数字->";
	int num = 0;
	cin >> num;
	int ret = fun(num);
	cout << num << "中的二进制位中的1的个数为：" << ret << endl;
	system("pause");
	return 0;
}