#pragma once
#include <iostream>
#include <string>
#include "Unit_Input_Output.h"
#include <time.h>

void TimeToStr(Datetime time_)
{
	struct tm tm = { 0 };
	tm.tm_year = time_.Year - 1900;
	tm.tm_mon = time_.Month - 1;
	tm.tm_mday = time_.Day;
	char date[28];
	strftime(date, 28, "%F", &tm);
	cout << date << endl;
	return;
}

void Outcard(int index)
{

	Librarycard card = cards[index - 1];
	cout << "Name: " << card.Name << endl;
	cout << "Number: " << card.Number << endl;
	cout << "Author: " << card.Author << endl;
	cout << "Date given: "; TimeToStr(card.Dategiven);
	cout << "Date returned: "; TimeToStr(card.Datereturn);
}

void OutOne()
{
	cout << "Enter index:";
	int index = 0;
	cin >> index;
	if (index <= SizeCard)
		Outcard(index);
}

void PrintAll()
{
	int index;
	cout << "+++++++++++++++++\n";
	for (index = 1; index <= SizeCard; index++)
	{
		Outcard(index);
		cout << "+++++++++++++++++\n";
	}
}