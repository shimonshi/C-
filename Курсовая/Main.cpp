#include <iostream>
#include "ATM.h"
using namespace std;

ATM sysATM;

void Menu()
{
	int ind = 0;

	do
	{
		system("cls");
		cout << "++++++++++++++++++++++++" << endl;
		cout << "+  1. Authentication   +" << endl;
		cout << "+  2. GiveMoney        +" << endl;
		cout << "+  3. Remove           +" << endl;
		cout << "+  4. Add              +" << endl;
		cout << "+  5. Search           +" << endl;
		cout << "+  6. Show all         +" << endl;
		cout << "+  7. Exit             +" << endl;
		cout << "++++++++++++++++++++++++" << endl;
		cout << "Enter the item number:\n> ";
		cin >> ind;
		if (!cin.fail())
		{
			switch (ind)
			{
			case 1:
				sysATM.AuthUser();
				break;
			case 2:
				sysATM.GiveMoney();
				break;
			case 3:
				//Search(1);
				break;
			case 4:
				//Add();
				break;
			case 5:
				//Search(0);
				break;
			case 6:
				//printAll();
				break;
			}
		}
		else
		{
			cin.clear();
			ind = 0;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (ind != 7);
}

int main(int argc, char* argv[])
{
	Menu();
}