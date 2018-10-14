#pragma once
struct Datetime
{
	int Day;
	int Month;
	int Year;
};

struct Librarycard
{

	char Name[128];
	char Number[256];
	char Author[256];
	Datetime Dategiven;
	Datetime Datereturn;
};

Librarycard* cards;
