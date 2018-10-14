
#include "Class.h"
#include <iostream>
#include <string>
#include <vector>
#include "LibraryUser.h"
using namespace std;

class Type_Of_Book : LibraryUser
{
public:
	Type_Of_Book();

	Type_Of_Book(int N, string A, string T, unsigned short day1, unsigned short month1, unsigned short year1, unsigned short day2, unsigned short month2, unsigned short year2);

	~Type_Of_Book();

	///////////////////////////////////////

	void set_Type();

	void set_Option();

	///////////////////////////////////////

	string get_Type();

	string get_Option();

	///////////////////////////////////////

	void Out_Type_Option(vector <Type_Of_Book> &Array);

	bool Is_Num_in_vector_v(int Num, vector <Type_Of_Book> Array);

	void solo_Art(vector <Type_Of_Book> &Array);

	void Inp_w(vector <Type_Of_Book> &Array);

	void Out_w(Type_Of_Book m);

private:
	string r;
	string t;
	///////////////////////////////////////
	string Type;
	string Option;
};
