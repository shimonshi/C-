#pragma once

using namespace std;

struct Datetime
{
	int Day;
	int Month;
	int Year;
};

struct Librarycard
{

	char Name[32];
	char Number[32];
	char Author[32];
	Datetime Dategiven;
	Datetime Datereturn;
};

int SizeCard = 0;
Librarycard* cards;
