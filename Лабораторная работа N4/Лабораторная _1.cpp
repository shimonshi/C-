#include <iostream>
#include <time.h>
#include <string>
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
	
Librarycard* cards;
int SizeCard = 0;
 
bool DateIn(Datetime* dateTime)
{
	cout << "\tEnter day:";
	cin >> dateTime->Day;
	if (!(dateTime->Day < 32 && dateTime->Day > 0))
	{
		return false;
	}
	cout << "\tEnter month:";
	cin >> dateTime->Month;
	if (!(dateTime->Month < 13 && dateTime->Month > 0))
	{
		return false;
	}
	cout << "\tEnter year:";
	cin >> dateTime->Year;
	if (!(dateTime->Year < 3000 && dateTime->Year >= 1900))
	{
		return false;
	}
	return true;
}

void SortDate()
{
	int j = 0;
	for (int index = 0; index < SizeCard; index++)
	{
		j = index;
		for (int k = index; k < SizeCard; k++)
		{
			if (cards[j].Dategiven.Year > cards[k].Dategiven.Year)
			{
				j = k;
			}
			else if (cards[j].Dategiven.Year == cards[k].Dategiven.Year)
			{
				if (cards[j].Dategiven.Month > cards[k].Dategiven.Month)
				{
					j = k;
				}
				else if (cards[j].Dategiven.Month == cards[k].Dategiven.Month)
				{
					if (cards[j].Dategiven.Day > cards[k].Dategiven.Day)
					{
						j = k;
					}
				}
			}
		}

		Librarycard tmp = cards[index];
		cards[index] = cards[j];
		cards[j] = tmp;
	}
	cout << "Sorted!" << endl;
}


void Add()
{

	Librarycard card = { 0 };
	Librarycard* tmpcards = NULL;
	bool check = false;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Name: ";
	cin.getline(card.Name, 31);	
	cout << "Enter Number: ";
	cin.getline(card.Number, 31);
	cout << "Enter Author: ";
	cin.getline(card.Author, 31);
	cout << "Enter Dategiven: " << endl;
	if (!DateIn(&card.Dategiven))
	{
		check = true;
	}
	else
	{

		cout << "Enter Datereturn: " << endl;
		if (!DateIn(&card.Datereturn))
		{
			check = true;
		}
	}
	if (check)
	{
		cout << "\n\n\t++ ERROR. ++\n\n";
	}
	else
	{
		SizeCard++;
		tmpcards = (Librarycard*)realloc(cards, SizeCard * sizeof(Librarycard));

		if (tmpcards != NULL)
		{
			cards = tmpcards;
			cards[SizeCard - 1] = card;
			cout << "\n\n\t++ Success. ++\n\n";
		}
		else
		{
			free(cards);
			cout << "Error (re)allocating memory";
		}
	}
	return;
}

void TimeToStr(Datetime* time_)
{
	struct tm tm={0};
	tm.tm_year = time_->Year - 1900;
	tm.tm_mon = time_->Month - 1;
	tm.tm_mday = time_->Day;
	char date[28];
	strftime(date, 28, "%F", &tm);
	cout << date << endl;
	return;
}

void Outcard(int index)
{
	
		Librarycard* card = &cards[index -1];
		cout << "Name: " << card->Name<<endl;
		cout << "Number: " << card->Number << endl;
		cout << "Author: " << card->Author << endl;
		cout << "cardsgiven: "; TimeToStr(&card->Dategiven);
		cout << "cardsreturn: "; TimeToStr(&card->Datereturn);
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

bool CheckReturn(Datetime Dategiven, Datetime Datereturn)
{
	
	struct tm tm = { 0 };
	tm.tm_year = Dategiven.Year - 1900;
	tm.tm_mon = Dategiven.Month - 1;
	tm.tm_mday = Dategiven.Day;
	time_t time_ = mktime(&tm);

	struct tm tm2 = { 0 };
	tm2.tm_year = Datereturn.Year - 1900;
	tm2.tm_mon = Datereturn.Month - 1;
	tm2.tm_mday = Datereturn.Day;
	time_t time_2 = mktime(&tm2);

	double diff = difftime(time_2, time_);
	return diff < 2592000;
}

void FailedToReturn()
{
	for (int index = 0; index < SizeCard; ++index)
	{
		if (!CheckReturn(cards[index].Dategiven, cards[index].Datereturn))
		{
			Outcard(index + 1);
		}
	}
}

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
			case 5:
				
				break;
			default:
				cout << "Input wrong command";
				break;
			}
		}
	}
}