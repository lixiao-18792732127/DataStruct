#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{
	}
	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_size = _capacity = 0;
		}
	}
	void PushBack(const T& x)            //?22?
	{
		_CheckCapacity();
		_array[_size++] = x;
	}
	void PopBack()                      //?2¨¦?
	{
		assert(_size > 0);
		--_size;
	}
	void PushFront(const T& x)          //¨ª¡¤2?
	{
		_CheckCapacity();
		size_t end = _size;
		_size += 1;
		while (end > 0)
		{
			_array[end] = _array[end - 1];
			end--;
		}
		_array[0] = x;
	}
	void PopFront()           //¨ª¡¤¨¦?
	{
		assert(_size > 0);
		size_t begin = 0;
		while (begin < _size)
		{
			_array[begin] = _array[begin + 1];
			begin++;
		}
		_size -= 1;
	}
	int Find(const T& x)        //2¨¦?¨°
	{
		size_t begin = 0;
		while (begin < _size)
		{
			if (_array[begin] == x)
			{
				return begin;
			}
			begin++;
		}
		return -1;
	}
	void Insert(size_t pos, const T& x)         //2?¨¨?
	{
		assert(pos <= _size);
		_CheckCapacity();
		size_t end = _size;
		_size += 1;
		while (end > pos)
		{
			_array[end] = _array[end - 1];
			end--;
		}
		_array[pos] = x;
	}
	void Erase(size_t pos)      //¨¦?3y
	{
		assert(pos < _size);
		size_t begin = pos;
		while (begin < _size)
		{
			_array[begin] = _array[begin + 1];
			begin++;
		}
		_size -= 1;
	}
	void Print()                              //¡ä¨°¨®??3D¨°¡À¨ª
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
protected:
	void _CheckCapacity()          //?¨¬2¨¦¨¨Y¨¢?
	{
		if (_size >= _capacity)
		{
			size_t newCapacity = _capacity * 2 + 3;
			T* tmp = new T[newCapacity];
			for (size_t i = 0; i < _size; ++i)
			{
				tmp[i] = _array[i];
			}
			delete[] _array;
			_array = tmp;
			_capacity = newCapacity;
		}
	}
protected:
	size_t _size;
	size_t _capacity;
	T* _array;
};

void Test()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.Print();
	/*v1.Insert(v1.Find(1), 5);
	v1.Insert(v1.Find(5), 6);
	v1.Print();*/
	v1.Erase(v1.Find(2));
	v1.Print();
	/*v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.Print();
	v1.PushFront(1);
	v1.PushFront(2);
	v1.PushFront(3);
	v1.PushFront(4);
	v1.Print();
	v1.PopFront();
	v1.PopFront();
	v1.PopFront();
	v1.PopFront();
	v1.PopFront();
	v1.Print();
	Vector<string> v2;
	v2.PushBack("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	v2.PushBack("bbb");
	v2.PushBack("ccc");
	v2.PushBack("ddd");
	v2.Print();*/
}
int main()
{
	Test();
	system("pause");
	return 0;
}
