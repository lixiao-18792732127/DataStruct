#include<iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
/*1,�ж�һ�Ŷ������Ƿ�Ϊƽ�������*/
int TreeDepth(TreeNode* _root)//ʹ�õݹ鷽������������ĸ߶�
{
	if (_root == NULL)
	{
		return 0;
	}
	int left = TreeDepth(_root->_left);
	int right = TreeDepth(_root->_right);
	return (left > right) ? (left + 1) : (right + 1);
}
bool IsBalanceTree(TreeNode* _root)
{
	if (_root == NULL)//����Ҳ��ƽ�������
	{
		return true;
	}
	int left = TreeDepth(_root->_left);//
	int right = TreeDepth(_root->_right);
	if ((left - right) > 1 || (left - right) < -1)//ƽ����������ж����������������������ĸ߶Ȳ����1
	{
		//����߶Ȳ�ľ���ֵ����1�����ش���
		return false;
	}
	else
	{
		return IsBalanceTree(_root->_left) && IsBalanceTree(_root->_right);
	}
}


bool IsBalanceTree(TreeNode* _root, int &Depth)
{
	if (_root == NULL)
	{
		Depth = 0;
		return true;
	}
	int left, right;
	if (IsBalanceTree(_root->_left, left) && IsBalanceTree(_root->_right, right))
	{
		int diff = left - right;//����һ����ֵ������߼�ȥ�ұ�
		if (diff < 1 && diff >= -1)
		{
			Depth = 1 + (left>right ? left : right);
			return true;
		}
	}
	return false;
}


/*��һ�Ŷ������ľ���*/
void MirrorRecurisively(TreeNode* _root)
{
	if (_root == NULL || (_root->_left == NULL) && _root->_right)
	{
		return;
	}
	TreeNode* tmp = _root->_left;
	_root->_left = _root->_right;
	_root->_right = tmp;
	if (_root->_left)
	{
		MirrorRecurisively(_root->_left);//�����������ĵݹ�
	}
	if (_root->_right)
	{
		MirrorRecurisively(_root->_right);
	}
}

/*һ��m*n�ľ��󣬴����Ҵ��ϵ��¶��ǵ����ģ���һ����x���ж�x�Ƿ��ھ����С�Ҫ��Ч�ʾ����ܵĸߡ�*/
#include<iostream>
using namespace std;
#include<assert.h>


bool Find(const int *a, int M ,int N, int x, int y, int &key)
{
	assert(a);
	while (x < M&&x >= 0 && y < M&&y >= 0)
	{
		int num = a[x*M + y];
		if (key>num)
		{
			x++;
		}
		else if (key<num)
		{
			y--;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void Judge(int ret, int key)
{
	if (ret == 1)
	{
		cout << "����" << key << "�ҵ��ˣ�" << endl;
	}
	else
	{
		cout << "����" << key << "û���ҵ���" << endl;
	}
}

int main()
{
	int a[20] = { 0 };
	int M = 0;
	int N = 0;
	cout << "������M��N��ֵ->" << endl;
	cin >> M >> N;
	cout << "�����������ֵ->" << endl;
	for (int i = 0; i < M*N; i++)
	{
		cin >> a[i]; 
	}
	cout << "�����ֵΪ��" << endl;
	for (int i = 1; i <= M*N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int num = 0; 
	cout << "������Ҫ���ҵ����֣�" << endl;
	cin >> num;
	int ret = Find(a, M, N, 0, M - 1, num);
	Judge(ret, num);
	system("pause");
	return 0;
}