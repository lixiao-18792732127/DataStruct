// 计算1+2+3+...+n，不使用循环等。
#include<iostream>
using namespace std;

class solute
{
public:
	int sum_solute(int n)
	{
		int res = n;
		res && (res += sum_solute(n - 1));
		return res;
	}
};

int main()
{
	solute s;
	int n = 0;
	cout << "请输入n的值" << endl;
	cin >> n;
	cout << "1加到" << n <<"的值为："<< s.sum_solute(n) << endl;
	system("pause");
	return 0;
}