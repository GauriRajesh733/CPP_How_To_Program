#include "CommissionEmployee.h"
#include <iostream>


CommissionEmployee::CommissionEmployee(const std::string& fName, const std::string& lName, double gSales, double cRate)
{
    firstName = fName;
    lastName = lName;
    grossSales = gSales;
    commissionRate = cRate;
}

void CommissionEmployee::setFirstName(std::string& newFName)
{
    firstName = newFName;
}

void CommissionEmployee::setLastName(std::string& newLName)
{
    lastName = newLName;

}

void CommissionEmployee::setGrossSales(double newGSales)
{
    grossSales = newGSales;
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double newCRate)
{
    commissionRate = newCRate;
}

double CommissionEmployee::getCommisionRate() const
{
    return commissionRate;
}

double CommissionEmployee::earnings() const
{
    return commissionRate * grossSales;
}

void CommissionEmployee::toString() const
{
    std::cout << firstName << " " << lastName << ": " << std::endl << "Gross Sales: " << grossSales << std::endl
        << "Commission Rate: " << commissionRate << std::endl;
}
