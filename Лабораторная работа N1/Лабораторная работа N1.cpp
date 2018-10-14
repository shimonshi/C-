#include <iostream>
#include <Windows.h>
#include <memory>

using namespace std;

// ���� ���������
void OutputMenu()
{
	cout << "���� ���������:" << endl;
	cout << "1 - ����������� ������" << endl;
	cout << "2 - ������������ ������" << endl;
	cout << "0 - ���������� ���������" << endl;
}

//���� ��� ������������� �������
void OutputMenu2()
{
	cout << "�������� �������:" << endl;
	cout << "1 - ���������� ���������� ��������� �������, ������������� ����� ������ ����������� � ��������� ������������ ����������" << endl;
	cout << "2 - ���������� ����� �������, ����� ������ ����������� � ��������� ������������, � ������� ����������� ��������� " << endl;
	cout << "3 - �������� �� ������� ���� ��������� ��������� ���������" << endl;
	cout << "4 - ���������� ����������� ������ �������� ��������� �������, ������� �������� ������� �����" << endl;
}
// ���������� ������� � ����������
void inp_array(int *x, int n)
{
	cout << "�������" << n << "�����" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
}

// ���������� ������� ���������� �������
void randinp_array(int *x, int n)
{
	for (int i = 0; i < n; i++)
		x[i] = 0 + rand() % 100;
}

// ����� ������� 
void out_array(int *x, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
}

//������������ ��������� ������� � ������� �������� ���� �����
void Decrease_series(int n)
{
	const int maxlen = 1000;
	int a[maxlen];
	int b[99]; // ������ ��������
	int c[99]; // ������ ��������
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
// ���������� ������� ������������ � ���������� ������������� ��������� �������
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
	cout << "\n���-�� ��������� ������� = " << s << endl << endl;
}

// ���������� ����� �������, ����� ������ ����������� � ��������� ������������, � ������� ����������� ��������� ������� ������ ������� 
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

// �������� �� ������� ���� ��������� ��������� ��������� 
void Del_Rep(int *x, int &n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				if (x[i] == x[j]) {
					swap(x[n - 1], x[j]);
					n--;
				}
}

//��� ���� ����� 
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

//�������� ����� �� �������� 
int Simple_Num(int k) {
	for (int i = 2; i <= sqrt(k); i++)
		if (k % i == 0)
			return 0;
	return 1;
}

// ���������� ����������� ������ �������� ��������� �������, ������� �������� ������� ����� 
void Great_Divisor(const int *x, int n) {
	int g;
	if (n >= 3) {
		g = x[2];
		for (int i = 3; i < n; i++)
			if (Simple_Num(i)) {
				g = gcd(g, x[i]);
			}
		cout << "\n���������� ����� ��������: " << g << endl << endl;
	}
	else
		cout << "\n��� ��������� ������� � �������� ���������\n" << endl;
}

// ������������ ������ 
void Switch_Case(int *x, int n) {
	int com;
	do {
		cout << "������� �������: ";
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
			cout << "������� �������� �������";
		}
	} while (com);
}