#include <iostream>
#include <string.h>

using namespace std;

class overload
{
public:
	overload()
	{
		length = 0;
		cout << "\nОбычный конструктор1\n";
	}

	overload(int* a, int n)
	{
		length = 0;
		for (int i = 0; i < n; i++)
			add(a[i]);
		cout << "\nОбычный конструктор2\n";
	}

	overload(const overload &obj)
	{
		length = 0;
		nums = new int;
		for (int i = 0; i < obj.length; i++)
			add(obj.nums[i]);
		cout << "\nКонструктор копирования\n";
	}

	~overload()
	{
		cout << "\nДеструктор\n";
	}

	int* nums;
	int length;

	int has(int n)
	{
		for (int i = 0; i < length; i++)
			if (n == nums[i])
				return 1;
		return 0;
	}

	void add(int n)
	{
		if (!has(n))
		{
			length++;
			nums = (int*)realloc(nums, sizeof(int)*length);
			nums[length - 1] = n;
		}
	}

	void set(int *a, int n)
	{
		length = 0;
		for (int i = 0; i < n; i++)
			add(a[i]);
	}

	friend ostream& operator<<(ostream& os, overload a)
	{
		os << "length = " << a.length << endl;
		if (a.length>0)
		{
			for (int i = 0; i < a.length; i++)
				os << a.nums[i] << " ";
			os << endl;
		}
		return os;
	}

	overload operator=(overload a)
	{
		if (&a == this) return *this;
		length = a.length;
		nums = (int*)realloc(nums, sizeof(int)*length);
		for (int i = 0; i < length; i++)
			nums[i] = a.nums[i];
		return *this;
	}
};
int operator==(overload a, overload b)
{
	if (a.length == b.length)
	{
		for (int i = 0; i < a.length; i++)
			if (!(b.has(a.nums[i])))
				return 0;
		return 1;
	}
	return 0;
}

overload operator||(overload &a, overload &b)
{
	for (int i = 0; i < b.length; i++)
	{
		a.add(b.nums[i]);
	}
	return a;
}