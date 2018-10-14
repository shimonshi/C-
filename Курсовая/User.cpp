#pragma once
#include "User.h"
#include <vector>

using namespace std;

User::User()
{
	login = "";
	password = "";
	balance = 0.0;
}

User::User(string ALogin, string APassword, float ABalance)
{
	login = ALogin;
	password = APassword;
	balance = ABalance;
}

bool User::ChangeBalance(float Offset)
{
	if (balance + Offset >= 0)
	{
		balance += Offset;
		return true;
	}
	else
	{
		return false;
	}
}

bool User::CheckPassword(string APassword)
{
	return APassword == password;
}

float User::GetBalance()
{
	return balance;
}