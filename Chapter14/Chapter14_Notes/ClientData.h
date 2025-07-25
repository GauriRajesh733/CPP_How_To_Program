#pragma once
#include <string>
class ClientData
{
public:
	ClientData(int = 0, const std::string& = "", const std::string& = "", double = 0.0);

	void setAccountNumber(int);
	int getAccountNumber() const;

	void setFirstName(const std::string&);
	std::string getFirstName() const;

	void setLastName(const std::string&);
	std::string getLastName() const;

	void setBalance(double);
	double getBalance() const;

private:
	int accountNumber;
	char firstName[10];
	char lastName[15]; // not using string since they use dynamically allocated space
	double balance;
};

