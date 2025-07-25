#include "ClientData.h"

ClientData::ClientData(int accountNumberValue, const std::string& firstNameValue, const std::string& lastNameValue, double balanceValue)
    : accountNumber(accountNumberValue), balance(balanceValue)
{
    setFirstName(firstNameValue);
    setLastName(lastNameValue);
}

void ClientData::setAccountNumber(int accountNumberValue)
{
    accountNumber = accountNumberValue;
}

int ClientData::getAccountNumber() const
{
    return accountNumber;
}

void ClientData::setFirstName(const std::string& firstNameString)
{
    size_t length{ firstNameString.size() };
    length = (length < 10 ? length : 9);
    firstNameString.copy(firstName, length);
    firstName[length] = '\0';

}

std::string ClientData::getFirstName() const
{
    return firstName;
}

void ClientData::setLastName(const std::string& lastNameString)
{
    size_t length{ lastNameString.size() };
    length = (length < 15 ? length : 14);
    lastNameString.copy(lastName, length);
    lastName[length] = '\0';
}

std::string ClientData::getLastName() const
{
    return lastName;
}

void ClientData::setBalance(double balanceValue)
{
    balance = balanceValue;
}

double ClientData::getBalance() const
{
    return balance;
}
