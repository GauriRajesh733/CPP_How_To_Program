#pragma once
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
	friend ostream& operator<<(ostream&, BankAccount);
public:
	
	BankAccount(int account, string ownerName, double balance = 0.0);

	void deposit(double);

	void withdraw(double);

	void applyInterest(double);

private:
	int accountNum;
	string ownerName;
	double balance;
	vector<string> actions;
};

