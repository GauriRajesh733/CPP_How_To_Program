#pragma once
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee :
    public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&,
        double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);

    double getBaseSalary();

    double earnings() const;

    void toString() const;
private:
    double baseSalary;
};

