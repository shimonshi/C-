
#include "stdafx.h"
#include "Class.h"
#include <vector>
#include <iostream>
#include "LibraryUser.h"

using namespace std;

bool digitcheck(unsigned int a)
{
	cin.clear();
	cin.sync();
	string s;
	getline(cin, s, '\n');
	for (auto x : s)
	{
		if (!isdigit(x))
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}

bool spellcheck(string a)
{
	cin.clear();
	cin.sync();
	for (auto x : a)
	{
		if ((x < 'A' || x > 'Z') && (x < 'a' || x > 'z') && (x < 'А' || x > 'Я') && (x < 'а' || x > 'я') && x != 'Ё'&& x != 'ё')
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}

LibraryUser::LibraryUser()
{

}

LibraryUser::LibraryUser(int N, string A, string T, unsigned short day1, unsigned short month1, unsigned short year1, unsigned short day2, unsigned short month2, unsigned short year2)
{
	Num = N;
	Author = A;
	Title = T;
	Give.day = day1;
	Give.month = month1;
	Give.year = year1;
	Back.day = day2;
	Back.month = month2;
	Back.year = year2;
}

LibraryUser :: ~LibraryUser()
{

}

///////////////////////////////////////

void LibraryUser::set_Number()
{
	cout << "Введите номер книги" << endl;
	cin >> a;
	while ((!digitcheck(a)) || a < 1 || a > 65535)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> a;
	}
	Num = a;
}

void LibraryUser::set_Author()
{
	cout << "Введите автора книги (Без пробелов!!!)" << endl;
	cin >> s;
	while (!spellcheck(s))
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> s;
	}
	Author = s;
}

void LibraryUser::set_Title()
{
	cout << "Введите название книги (Без пробелов!!!)" << endl;
	cin >> s1;
	while (!spellcheck(s1))
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> s1;
	}
	Title = s1;
}

void LibraryUser::set_Give()
{
	cout << "Введите дату выдачи книги" << endl;
	cout << "День: ";
	cin >> d.day;
	while ((!digitcheck(d.day)) || d.day < 1 || d.day > 31)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d.day;
	}
	cout << "Месяц: ";
	cin >> d.month;
	while ((!digitcheck(d.month)) || d.month < 1 || d.month > 12)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d.month;
	}
	cout << "Год: ";
	cin >> d.year;
	while ((!digitcheck(d.year)) || d.year < 1 || d.year > 2018)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d.year;
	}
	Give = d;
}

void LibraryUser::set_Back()
{
	cout << "Введите дату возврата книги" << endl;
	cout << "День: ";
	cin >> d1.day;
	while ((!digitcheck(d1.day)) || d1.day < 1 || d1.day > 31)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d1.day;
	}
	cout << "Месяц: ";
	cin >> d1.month;
	while ((!digitcheck(d1.month)) || d1.month < 1 || d1.month > 12)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d1.month;
	}
	cout << "Год: ";
	cin >> d1.year;
	while ((!digitcheck(d1.year)) || d1.year < 1 || d1.year > 2018 || (d1.day < d.day && d1.month <= d.month && d1.year <= d.year) || (d1.month < d.month && d1.year <= d.year) || (d1.year < d.year))
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> d1.year;
	}
	cout << endl;
	Back = d1;
}

///////////////////////////////////////
int LibraryUser::get_Number()
{
	return Num;
}

string LibraryUser::get_Author()
{
	return Author;
}

string LibraryUser::get_Title()
{
	return Title;
}

Date LibraryUser::get_Give()
{
	return Give;
}

Date LibraryUser::get_Back()
{
	return Back;
}

///////////////////////////////////////

void LibraryUser::Inp_v(vector <LibraryUser> &Array)
{
	LibraryUser a;
	a.set_Number();
	a.set_Author();
	a.set_Title();
	a.set_Give();
	a.set_Back();

	Array.push_back(a);
}

void LibraryUser::Out_v(LibraryUser m)
{
	cout << m.get_Number() << ", " << m.get_Author() << ", " << m.get_Title() << endl;
	cout << m.get_Give().day << "." << m.get_Give().month << "." << m.get_Give().year << endl;
	cout << m.get_Back().day << "." << m.get_Back().month << "." << m.get_Back().year << endl << endl;
}

void LibraryUser::Out_Title_Back(vector <LibraryUser> Array)
{
	int a;
	cout << "Введите инвентарный номер книги" << endl;
	cin >> a;
	while ((!digitcheck(a)) || a < 1 || a > 65535)
	{
		cout << "Попробуйте еще раз" << endl;
		cin >> a;
	}
	for each  (LibraryUser i in Array)
	{
		if (i.get_Number() == a)
		{
			cout << "Автор этой книги: ";
			cout << i.get_Author() << endl;
			cout << "Дата возврата этой книги: ";
			cout << i.get_Back().day << "." << i.get_Back().month << "." << i.get_Back().year << endl;
		}
	}
}

bool LibraryUser::Is_Num_in_vector(int Num, vector <LibraryUser> Array)
{
	for each (LibraryUser i in Array)
	{
		if (Num == i.get_Number())
			return true;
	}
	return false;
}

void LibraryUser::solo_Author(vector <LibraryUser> Array)
{
	int a, i1;
	string s;
	for (i1 = 0; i1 < 2; i1++)
	{
		cout << "Введите инвентарный номер книги" << endl;
		cin >> a;
		while ((!digitcheck(a)) || a < 1 || a > 65535 || (!Is_Num_in_vector(a, Array)))
		{
			cout << "Попробуйте еще раз" << endl;
			cin >> a;
		}
		for each (LibraryUser i in Array)
		{
			if (i.get_Number() == a)
				if (i1 == 1)
					if (s == i.get_Author())
						cout << "У этих книг один автор" << endl;
					else
						cout << "У этих книг разные авторы" << endl;
				else
					s = i.get_Author();
		}
	}
}
