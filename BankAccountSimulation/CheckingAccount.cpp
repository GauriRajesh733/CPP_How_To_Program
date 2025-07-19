#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int account, string username, double initialBalance)
	: BankAccount::BankAccount(account, username, initialBalance)
{
}

void CheckingAccount::debit(double amount)
{
	// if amount is negative or less than or equal to balance charge normally
	if (amount < 0 || amount <= balance) {
		BankAccount::debit(amount);
	}
	// if amount is greater than balance charge additional overdraft fee 
	else {
		std::cout << "Overdraft Fee: -$30.00.  Charged $" << (amount + 30) << " in total." << std::endl;
		balance -= (amount + 30);
	}
}
