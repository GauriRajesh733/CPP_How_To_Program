#pragma once
#include <string>

class CommissionEmployee
{
public:
	// RECALL: string& used instead of string so copy is not made!
	CommissionEmployee(const std::string&, const std::string&,
		double = 0.0, double = 0.0);

	void setFirstName(std::string&);

	void setLastName(std::string&);

	void setGrossSales(double);
	double getGrossSales() const;

	void setCommissionRate(double);
	double getCommisionRate() const;

	double earnings() const;
	void toString() const;
private:
	std::string firstName;
	std::string lastName;
	double grossSales;
	double commissionRate;
};

