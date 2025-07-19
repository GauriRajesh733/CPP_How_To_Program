#include "Bank.h"
#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

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
	string username;
	double balance;
	string password;
	string savings;
	bool isSavings;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (true) {
		cout << "Enter Username: ";
		getline(cin, username); // no cin.ignore needed here

		// NOTE: no need for cignore here because getline handles it
		if (logins.find(username) != logins.end()) {
			cout << "Account with username already exists, please enter a new username." << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Enter Initial Deposit: ";
		cin >> balance;

		// check if balance is double amount
		if (cin.fail()) {
			cout << "Invalid initial deposit, please enter a valid amount." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	cout << "Enter Password: ";
	getline(cin, password);

	while (true) {
		cout << "Enter 'S' for savings account and 'C' for checking account: ";
		cin >> savings;

		if (savings != "S" && savings != "C") {
			cout << "Please enter S or C to specify account type." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	isSavings = (savings == "S");

	BankAccount* newAccount;

	if (isSavings) {
		newAccount = new SavingsAccount(++totalAccounts, username, balance);
	}
	else {
		newAccount = new CheckingAccount(++totalAccounts, username, balance);
	}

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

	logins.insert({ username, password });
	cout << "Username: " << username << " Password: " << logins[username] << endl;

	if (isSavings) {
		cout << "Savings Bank Account #" << totalAccounts << " created." << endl;

	}
	else {
		cout << "Checking Bank Account #" << totalAccounts << " created." << endl;
	}

}

void Bank::credit()
{
	if (currentAccount == 0) {
		cout << "Please log into account before depositing amount." << endl;
		return;
	}

	double amount;
	cout << "Enter Deposit Amount: ";
	cin >> amount;

	accounts[currentAccount - 1]->credit(amount);
}

void Bank::debit()
{
	if (currentAccount == 0) {
		cout << "Please log into account before withdrawing amount." << endl;
		return;
	}

	double amount;
	cout << "Enter Amount to Withdraw: ";
	cin >> amount;

	accounts[currentAccount - 1]->debit(amount);
}

void Bank::applyInterest()
{
	if (currentAccount == 0) {
		cout << "Please log into account before applying interest." << endl;
		return;
	}

	SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*> (accounts[currentAccount - 1]);
	if (savingsAccount == nullptr) {
		cout << "Cannot apply interest to checking account." << endl;
		return;
	}
	
	savingsAccount->applyInterest(interestRate);
}

void Bank::displayAccount()
{
	if (currentAccount == 0) {
		cout << "Please log into account before displaying details." << endl;
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
	string username;
	string password;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Username: ";
	getline(cin, username);
	cout << "Enter Password: ";
	getline(cin, password);

	if (logins.find(username) == logins.end()) {
		cout << "Bank Account with username " << username << " does not exist." << endl;
		return;
	}
	
	if (logins[username] != password) {
		cout << "Incorrect Password.  Please try again." << endl;
		return;
	}

	for (int i = 0; i < totalAccounts; i++) {

		if (accounts[i] && accounts[i]->getUsername() == username) {
			currentAccount = accounts[i]->getAccountNumber();
			cout << "Logged Into Account #" << accounts[i]->getAccountNumber() << endl;
			return;
		}
	}

	cout << "Bank Account with username " << username << " does not exist." << endl;
	return;
}

void Bank::logout()
{
	cout << "Logged Out of Account #" << currentAccount << endl;
	currentAccount = 0;
}
