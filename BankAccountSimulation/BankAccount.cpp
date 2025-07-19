#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int account, string user, double initialBalance)
{
	accountNum = account;
	username = user;
	if (initialBalance < 0) {
		cout << "Initial balance cannot be negative, set to $0.00.";
	}

	balance = initialBalance < 0.00 ? 0.00 : initialBalance;

}

void BankAccount::credit(double amount) {
	if (amount < 0) {
		cout << "Deposit amount cannot be negative." << endl;
		return;
	}
	balance += amount;
	cout << "$" << amount << " deposited into account #" << accountNum << endl;
	actions.push_back("Deposited $" + to_string(amount) + ".");
}

void BankAccount::debit(double amount) {
	if (amount < 0) {
		cout << "Cannot withdraw negative amount." << endl;
		return;
	}
	if (amount > balance) {
		cout << "Insufficient funds in account." << endl;
		return;
	}

	balance -= amount;
	cout << "$" << amount << " withdrawn from account #" << accountNum << endl;
	actions.push_back("Withdrew $" + to_string(amount) + ".");
}

string BankAccount::getUsername()
{
	return username;
}

int BankAccount::getAccountNumber()
{
	return accountNum;
}

ostream& operator<<(ostream& output, BankAccount acc)
{
	output << "Account #" << acc.accountNum << ":" << endl;
	output << "Username: " << acc.username << endl;
	output << "Balance: " << acc.balance << endl;
	// add transactions

	if (acc.actions.size() == 0) {
		output << "No Recent Transactions" << endl;
		return output;
	}

	output << "Recent Transactions: " << endl;
	for (string action : acc.actions) {
		output << action << endl;
	}

	return output;
}
