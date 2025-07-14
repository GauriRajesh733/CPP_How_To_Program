#include "Bank.h"
#include <iostream>
using namespace std;


Bank::Bank(double rate)
{
	currentAccount = 0;
	interestRate = rate;
	totalAccounts = 0;
	capacity = 4;
	accounts = new BankAccount*[capacity];

}

void Bank::createAccount()
{
	string name;
	double balance;
	string password;

	cout << "Enter Name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << "Enter Initial Deposit: ";
	cin >> balance;
	cout << "Enter Password: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, password);

	// NOTE: created w new keyword so it is not destroyed at end of scope or createAccount()
	BankAccount* newAccount = new BankAccount(++totalAccounts, name, balance);

	if (totalAccounts > capacity) {
		cout << "Doubling bank account capacity to accomodate new account." << endl;
		capacity *= 2;
		BankAccount** temp = new BankAccount*[capacity * 2];
		
		for (int i = 0; i < capacity / 2; i++) {
			temp[i] = accounts[i];
		}

		delete[] accounts;
		accounts = temp;
		accounts[totalAccounts - 1] = newAccount;
		temp = nullptr;
	}
	else {
		accounts[totalAccounts - 1] = newAccount;
	}

	logins.insert({ totalAccounts, password });
	cout << "Bank Account #" << totalAccounts << " created." << endl;

}

void Bank::deposit()
{
	if (currentAccount == 0) {
		cout << "Please specify or create an account before depositing amount." << endl;
		return;
	}

	double amount;
	cout << "Enter Deposit Amount: ";
	cin >> amount;

	accounts[currentAccount - 1]->deposit(amount);
}

void Bank::withdraw()
{
	if (currentAccount == 0) {
		cout << "Please specify or create an account before withdrawing amount." << endl;
		return;
	}

	double amount;
	cout << "Enter Amount to Withdraw: ";
	cin >> amount;

	accounts[currentAccount - 1]->withdraw(amount);
}

void Bank::applyInterest()
{
	if (currentAccount == 0) {
		cout << "Please specify or create an account before applying interest." << endl;
		return;
	}

	accounts[currentAccount - 1]->applyInterest(interestRate);
}

void Bank::displayAccount()
{
	if (currentAccount == 0) {
		cout << "Please specify or create an account before displaying details." << endl;
		return;
	}
	cout << *accounts[currentAccount - 1];
}

void Bank::listAccounts()
{
	if (totalAccounts == 0) {
		cout << "No Bank Accounts Created." << endl;
		return;
	}

	cout << "Bank Accounts: " << endl;

	for (int i = 0; i < totalAccounts; i++) {
		cout << *accounts[i];
	}
}

void Bank::login()
{
	int accountNum;
	string password;
	cout << "Enter Account #: ";
	cin >> accountNum;
	cout << "Enter Password: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, password);

	if (logins.find(accountNum) == logins.end()) {
		cout << "Bank Account #" << accountNum << " does not exist." << endl;
		return;
	}
	
	if (logins[accountNum] != password) {
		cout << "Incorrect Password.  Please try again." << endl;
		return;
	}

	currentAccount = accountNum;
	cout << "Logged Into Account #" << currentAccount << endl;
}

void Bank::logout()
{
	cout << "Logged Out of Account #" << currentAccount << endl;
	currentAccount = 0;
}
