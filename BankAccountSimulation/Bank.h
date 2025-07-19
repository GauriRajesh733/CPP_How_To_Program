#pragma once
#include <map>
#include <string>
#include <array>
#include "BankAccount.h"
using namespace std;

class Bank
{
public:
	Bank(double interestRate = 0.05);

	void createAccount();

	void credit();

	void debit();

	void applyInterest();

	void displayAccount();

	void listAccounts();

	void login();

	void logout();

private:
	BankAccount** accounts;
	int currentAccount;
	int capacity;
	int totalAccounts;
	double interestRate;
	map<string, string> logins;
};

