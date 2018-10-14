#include <iostream>
#include <Windows.h>
#include <memory>

using namespace std;

// Меню программы
void OutputMenu()
{
	cout << "Меню программы:" << endl;
	cout << "1 - статический массив" << endl;
	cout << "2 - динамический массив" << endl;
	cout << "0 - завершение программы" << endl;
}

//Меню для динамического массива
void OutputMenu2()
{
	cout << "Выберете команду:" << endl;
	cout << "1 - нахождение количества элементов массива, расположенных между первым минимальным и последним максимальным элементами" << endl;
	cout << "2 - сортировка части массива, между первым минимальным и последним максимальным, в порядке возрастания элементов " << endl;
	cout << "3 - удаление из массива всех повторных вхождений элементов" << endl;
	cout << "4 - нахождение наибольшего общего делителя элементов массива, имеющих индексом простое число" << endl;
}
// Заполнение массива с клавиатуры
void inp_array(int *x, int n)
{
	cout << "Введите" << n << "чисел" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
}

// Заполнение массива случайными числами
void randinp_array(int *x, int n)
{
	for (int i = 0; i < n; i++)
		x[i] = 0 + rand() % 100;
}

// Вывод массива 
void out_array(int *x, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
}

//Расположение элементов массива в порядке убывания длин серий
void Decrease_series(int n)
{
	const int maxlen = 1000;
	int a[maxlen];
	int b[99]; // Массив счечиков
	int c[99]; // Массив индексов
	for (int i = 0; i < n; i++)
		b[a[i]]++;
	for (int i = 0; i < 98; i++)
		for (int j = 0; j < 98 - i; j++)
			if (b[j] < b[j - 1])
			{
				swap(b[j], b[j + 1]);
				swap(c[j], c[j + 1]);
			}
	for (int i = 0; i < 99; i++)
		for (int j = 0; j < b[c[i]]; j++)
			cout << c[i];
}
// Нахождение первого минимального и последнего максимального элементов массива
void Min_Max(int *x, int n)
{
	int first, second;
	int mymin = INT_MAX;
	int mymax = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (x[i] < mymin)
		{
			mymin = x[i];
			first = i;
		}
		if (x[i] > mymax)
		{
			mymax = x[i];
			second = i;
		}
	}
}

void Num_Element(int *x, int n) {
	int first, second, beg, end;
	Min_Max(x, n, &first, &second);
	int s = abs(second - first) - 1;
	cout << "\nКол-во элементов массива = " << s << endl << endl;
}

// Сортировка части массива, между первым минимальным и последним максимальным, в порядке возрастания элементов методом прямой вставки 
void Sort_Increase(int *x, int n) {
	int first, second, beg, end;
	Min_Max(x, n, &first, &second);
	if (second > first) {
		end = second;
		beg = first;
	}
	else {
		beg = first;
		end = second;
	}
	int temp, item;
	for (int i = beg + 2; i < end; i++) {
		temp = x[i];
		item = i - 1;
		while (item && x[item] > temp) {
			x[item + 1] = x[item];
			x[item] = temp;
			item--;
		}
	}

}

// Удаление из массива всех повторных вхождений элементов 
void Del_Rep(int *x, int &n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				if (x[i] == x[j]) {
					swap(x[n - 1], x[j]);
					n--;
				}
}

//НОД двух чисел 
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

//Проверка числа на простоту 
int Simple_Num(int k) {
	for (int i = 2; i <= sqrt(k); i++)
		if (k % i == 0)
			return 0;
	return 1;
}

// Нахождение наибольшего общего делителя элементов массива, имеющих индексом простое число 
void Great_Divisor(const int *x, int n) {
	int g;
	if (n >= 3) {
		g = x[2];
		for (int i = 3; i < n; i++)
			if (Simple_Num(i)) {
				g = gcd(g, x[i]);
			}
		cout << "\nНаибольший общий делитель: " << g << endl << endl;
	}
	else
		cout << "\nНет элементов массива с простыми индексами\n" << endl;
}

// Динамический массив 
void Switch_Case(int *x, int n) {
	int com;
	do {
		cout << "Введите команду: ";
		cin >> com;
		switch (com) {
		case 1:
			Num_Element(x, n);
			break;
		case 2:
			Sort_Increase(x, n);
			out_array(x, n);
			break;
		case 3:
			Del_Rep(x, n);
			out_array(x, n);
			break;
		case 4:
			Great_Divisor(x, n);
			break;
		case 0:
			system("cls");
			return;
		default:
			cout << "Введена неверная команда";
		}
	} while (com);
}