#include<iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};
/*1,判断一颗二叉树是否为平衡二叉树*/
int TreeDepth(TreeNode* _root)//使用递归方法求出二叉树的高度
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
	if (_root == NULL)//空树也是平衡二叉树
	{
		return true;
	}
	int left = TreeDepth(_root->_left);//
	int right = TreeDepth(_root->_right);
	if ((left - right) > 1 || (left - right) < -1)//平衡二叉树的判断条件，左子树与右子树的高度差不大于1
	{
		//如果高度差的绝对值大于1，返回错误
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
		int diff = left - right;//定义一个数值等于左边减去右边
		if (diff < 1 && diff >= -1)
		{
			Depth = 1 + (left>right ? left : right);
			return true;
		}
	}
	return false;
}


/*求一颗二叉树的镜像*/
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
		MirrorRecurisively(_root->_left);//进行左子树的递归
	}
	if (_root->_right)
	{
		MirrorRecurisively(_root->_right);
	}
}

/*一个m*n的矩阵，从左到右从上到下都是递增的，给一个数x，判断x是否在矩阵中。要求效率尽可能的高。*/
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
		cout << "数字" << key << "找到了！" << endl;
	}
	else
	{
		cout << "数字" << key << "没有找到！" << endl;
	}
}

int main()
{
	int a[20] = { 0 };
	int M = 0;
	int N = 0;
	cout << "请输入M和N的值->" << endl;
	cin >> M >> N;
	cout << "请输入数组的值->" << endl;
	for (int i = 0; i < M*N; i++)
	{
		cin >> a[i]; 
	}
	cout << "数组的值为：" << endl;
	for (int i = 1; i <= M*N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int num = 0; 
	cout << "请输入要查找的数字：" << endl;
	cin >> num;
	int ret = Find(a, M, N, 0, M - 1, num);
	Judge(ret, num);
	system("pause");
	return 0;
}