#pragma once
#include "BankAccount.h"
class CheckingAccount :
    public BankAccount
{
public:
    CheckingAccount(int account, string username, double initialBalance);

    void debit(double) override;
};

