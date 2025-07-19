#pragma once
#include "BankAccount.h"

class SavingsAccount :
    public BankAccount
{
public: 
	SavingsAccount(int account, string username, double initialBalance);

	void applyInterest(double rate);
};

