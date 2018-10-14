/*P��������� ������� ���������� ����������.
����������: ����������� ������������; ������ ��������; ������������ ���������; ������ ���������� ��������; ������ ���������; ����� � ���������� ��������*/
#pragma once
#include <string>
#include <map>
#include "User.h"

using namespace std;

struct Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

class ATM
{
public:
	ATM();
	
	void AuthUser();
	bool Auth(string ALogin, string APassword);
	int MoneyOperation();
	bool PayMobile();
	bool PayISP();
private:
	map<string, User> Users;
	User* currentUser;
	string FormPaymentReceipt();
	bool LoadFromFile();
};