#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool digitcheck(unsigned int a);
bool spellcheck(string a);

struct Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

class LibraryUser
{
public:
	LibraryUser();

	LibraryUser(int N, string A, string T, unsigned short day1, unsigned short month1, unsigned short year1, unsigned short day2, unsigned short month2, unsigned short year2);

	~LibraryUser();

	///////////////////////////////////////
	void set_Number();

	void set_Author();

	void set_Title();

	void set_Give();

	void set_Back();

	///////////////////////////////////////
	int get_Number();

	string get_Author();

	string get_Title();

	Date get_Give();

	Date get_Back();

	///////////////////////////////////////

	void Out_Title_Back(vector <LibraryUser> Array);

	void Inp_v(vector <LibraryUser> &Array);

	void Out_v(LibraryUser m);

	bool Is_Num_in_vector(int Num, vector <LibraryUser> Array);

	void solo_Author(vector <LibraryUser> Array);

private:
	int a;
	string s;
	string s1;
	Date d;
	Date d1;
	///////////////////////////////////////
	int Num;
	string Author;
	string Title;
	Date Give;
	Date Back;
};
