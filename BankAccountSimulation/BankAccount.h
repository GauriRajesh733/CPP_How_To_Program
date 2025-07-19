#pragma once
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
	friend ostream& operator<<(ostream&, BankAccount);
public:
	
	BankAccount(int account, string username, double balance = 0.0);

	void credit(double);

	virtual void debit(double);

	string getUsername();

	int getAccountNumber();

protected:
	int accountNum;
	string username;
	double balance;
	vector<string> actions;
};

