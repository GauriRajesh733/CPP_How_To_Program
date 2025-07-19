#include "BasePlusCommissionEmployee.h"
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& fName, const std::string& lName,
    double gSales, double cRate, double bSalary) : CommissionEmployee(fName, lName, gSales, cRate) {
    setBaseSalary(bSalary);
}

void BasePlusCommissionEmployee::setBaseSalary(double bSalary)
{
    baseSalary = bSalary;
}

double BasePlusCommissionEmployee::getBaseSalary()
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::toString() const {
    CommissionEmployee::toString();
    std::cout << "Base Salary: " << baseSalary << std::endl;
}
