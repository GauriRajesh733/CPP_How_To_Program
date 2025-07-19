#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int account, string username, double initialBalance)
	: BankAccount::BankAccount(account, username, initialBalance)
{
}

void SavingsAccount::applyInterest(double rate)
{
	balance = balance + balance * rate;
	std::cout << "Interest Applied To Savings Account #" << accountNum << std::endl;
	actions.push_back("Applied " + to_string(rate) + " interest.");
}
