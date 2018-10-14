#include "ATM.h"
#include "User.h"
#include <fstream>

using namespace std;

ATM::ATM()
{
	currentUser = NULL;
	if (!LoadFromFile()) 
	{
		cout << "Failed to load user list";
	}
}

void ATM::AuthUser()
{
	string login, password;
	cout << "Enter login:\n>";
	getline(cin >> ws, login);
	cout << "Enter password:\n>";
	getline(cin >> ws, password);
	if (Auth(login, password))
	{
		cout << "Success!" << endl;
		system("pause");
	}
	else
	{
		cout << "Error!" << endl;
		system("pause");
	}
}

bool ATM::Auth(string ALogin, string APassword)
{
	if (Users.find(ALogin) != Users.end())
	{
		if (Users[ALogin].CheckPassword(APassword))
		{
			currentUser = &Users[ALogin];
			return true;
		}
	}
	return false;
}

int ATM::MoneyOperation()
{
	system("cls");
	int amount;
	cin >> amount;
	try
	{
		do
		{

			if (currentUser == NULL)
			{
				cout << "Log in!" << endl;
				return 0;
			}
			else
			{
				cout << "Enter Amount: " << endl;
				cin >> amount;
				if (amount > 0 && amount > currentUser->balance)
				{
					cout << "You have no such means! Request a smaller amount." << endl;
				}
				else
				{
					currentUser->balance = currentUser->balance - amount;
					cout << "Success!";
				}
			}
		} while (amount > 0 && amount > currentUser->balance);
		return amount;
	}
	catch (char amount)
	{
		cout << "Requires Input Numbers! " << endl;
	}
	return 0;
}


bool ATM::PayMobile()
{
	system("cls");
	long MobileNumber;
	cin >> MobileNumber;
	try
	{
		do
		{

			if (currentUser == NULL)
			{
				cout << "Log in!" << endl;
				return 0;
			}
			else
			{
				cout << "How much you want to take? " << endl;
				cin >> MobileNumber;
				if (MobileNumber > 9000000000 && MobileNumber < 9999999999)
				{
					MoneyOperation();
				}
				else
				{
					cout << "Requires Input Numbers! " << endl;
				}
			}
		} while (amount > 0 && amount > currentUser->balance);
		return amount;
	}
	catch (char amount)
	{
		cout << "Requires Input Numbers! " << endl;
	}
	return 0;
}

bool ATM::PayISP()
{
	return true;
}

string ATM::FormPaymentReceipt()
{
	return "";
}

bool ATM::LoadFromFile()
{
	ifstream myfile("users.txt");
	string line;
	try {
		if (myfile)  // same as: if (myfile.good())
		{
			while (!myfile.eof())  // same as: while (getline( myfile, line ).good())
			{
				string login, password;
				float balance;

				getline(myfile, login);
				getline(myfile, password);
				getline(myfile, line);
				balance = stof(line);

				User tmpUser(login, password, balance);
				Users[login] = tmpUser;
			}
			myfile.close();
		}
	}
	catch (const ifstream::failure& e)
	{
		return false;
	}
	return true;
}