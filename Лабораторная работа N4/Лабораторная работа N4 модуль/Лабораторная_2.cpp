
#include <iostream>
#include <string>
#include "Unit_Operation.h"
#include "Unit_Input_Output.h"
#include "Unit_Def.h"

using namespace std;

int main()
{
	int command;
	while (true)
	{
		cout << "Enter command: ";
		cin >> command;
		if (cin.fail())
		{
			cout << "requires input number!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			command = 0;
		}
		else
		{
			switch (command)
			{
			case 1:
				Add();
				break;
			case 2:
				PrintAll();
				break;
			case 3:
				SortDate();
				break;
			case 4:
				FailedToReturn();
				break;
			default:
				cout << "Input wrong command";
				break;
			}
		}
	}
}