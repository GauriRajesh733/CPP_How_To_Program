#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int account, string owner, double initialBalance)
{
	accountNum = account;
	ownerName = owner;
	balance = initialBalance;
}

void BankAccount::deposit(double amount) {
	if (amount < 0) {
		cout << "Deposit amount cannot be negative." << endl;
		return;
	}
	balance += amount;
	cout << "$" << amount << " deposited into account #" << accountNum << endl;
	actions.push_back("Deposited $" + to_string(amount) + ".");
}

void BankAccount::withdraw(double amount) {
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

void BankAccount::applyInterest(double rate) {
	balance = balance + balance * rate;
	cout << "Interest Applied To Account #" << accountNum;
	actions.push_back("Applied " + to_string(rate) + " interest.");

}

ostream& operator<<(ostream& output, BankAccount acc)
{
	output << "Account #" << acc.accountNum << ":" << endl;
	output << "Owner: " << acc.ownerName << endl;
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
