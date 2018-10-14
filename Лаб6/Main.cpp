#pragma once
#include "Class.h"

int main()

{
	setlocale(LC_CTYPE, "RUS");

	overload a;
	int ar[5] = { 1,2,3,4,5 };
	int* p = ar;
	overload b(p, 5);
	cout << b;
	cout << (a == b) << endl;
	a = b;
	cout << a;
	ar[3] = 7;
	overload c;
	c.set(p, 5);
	cout << c;
	cout << (a == c);
	a = a || c;
	cout << a;
}