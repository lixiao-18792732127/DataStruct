// ����1+2+3+...+n����ʹ��ѭ���ȡ�
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
	cout << "������n��ֵ" << endl;
	cin >> n;
	cout << "1�ӵ�" << n <<"��ֵΪ��"<< s.sum_solute(n) << endl;
	system("pause");
	return 0;
}