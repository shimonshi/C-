#pragma once

#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	float balance;
	User();
	User(string ALogin, string APassword, float ABalance);
	bool ChangeBalance(float Offset);
	bool CheckPassword(string APassword);
	float GetBalance();
	int MobileNumber;
private:
	string login;
	string password;
};