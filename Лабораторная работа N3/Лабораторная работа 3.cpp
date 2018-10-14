 
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <string>


using namespace std;

void Check(char *charr) // Проверка на 10 сс.
{
	bool flag = true;
	int count = 0;
	int ch;
	cout << "Enter Number" << endl;
	while ((ch = _getch()) != 13)
	{
		cout << (char)ch;
		// Считать символ
		if ((ch > 48) && (ch < 57))
		{
			charr[count] = ch;

		}
		else
		{
			flag = false;
			break;
		}
		count++;
		if (count == 13)
			break;
	}
	if (!flag)
		charr[0] = 0;
}

void RecordNumber() // Запись числа в строкой форме.
{
	try
	{
		char charr[13] = { 0 };
		Check(charr);
		if (charr[0] == 0)
			cout << endl << "Error"<<endl;
		else
		{
			int number = atoi(charr);
			cout << endl << number << endl;
		}
	}
	catch (exception const &e)
	{
		cout << endl << "Error: " << e.what() << endl;
	}
}

string Replace(string in)
{
	in.erase(unique(in.begin(), in.end()), in.end());
	return in;
}

string Swap(string in)
{
	in = in[in.length() - 1] + in.substr(0, in.length()-1);
	return in;
}
void WordOutput()
{
	string str;
	size_t pos = 0;
	string token;

	cout << "Введите строку: " << endl;
	ws(cin);
	getline(cin, str);

	while (str.length() > 0)
	{
		pos = str.find_first_of(", ");
		if (pos == string::npos)
			pos = str.length();
		else if (pos == 0)
		{
			str.erase(0, 1);
			continue;
		}
		token = str.substr(0, pos);
		token = Replace(token);
		token = Swap(token);
		cout << "\tСлово:" << token << endl;
		str.erase(0, pos + 1);
	}
}	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int command;
	while (true)
	{
		cout << "Введите команду: ";
		cin >> command;
		if (cin.fail())
		{
			cout << "Необходим ввод числа! " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			command = 0;
		}
		else
		{
			switch (command)
			{
			case 1:
				RecordNumber();
				break;
			case 2:
				WordOutput();
				break;
			default:
				cout << "Введена неверная команда: ";
				break;
			}
		}
	}
}
