#include <iostream>
#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"

int main()
{
    // RECALL: inheritance, base class, derived class,
    // subclass
    // NOTE: public, protected, and private inheritance (this chapter 
    // focuses on public inheritance however)

    // RECALL: inheritance vs composition
    // -> "is a " vs "has a"

    // NOTE: C++ supports MULTIPLE INHERITANCE (derived class inherits 
    // from many possibly unrelated base classes)
    
    // ex. BasePlusCommission and Commission Employees
    CommissionEmployee ce("commission", "employee", 1000, 20);
    ce.toString();
    std::cout << "Earnings: " << ce.earnings() << std::endl;


    BasePlusCommissionEmployee bpce("base plus commission", "employee", 1000, 20, 50);
    bpce.toString();
    std::cout << "Earnings: " << bpce.earnings() << std::endl;

    // RECALL: making fields protected in CommissionEmployee enables access to 
    // derived classes such as BasePlusCommissionEmployee
    // NOTE: however, generally keep all fields private
    // this also causes issues if base class field names change for ex, it needs to be
    // changed in all derived classes that directly reference the protected fields!

    // NOTE: constructors and destructors
    // first invoke direct base class constructor explicitly or implicitly, then call the constructor
    // of the next class up in hierarchy if needed and so on, and finally the constructor of the 
    // most-derived class.  destructors are called in reverse order of constructor calls.


    // NOTE: if inheriting constructor with same params can use:
    // using BaseClass::BaseClass


    // NOTE: protected inheritance (rarely used)

    // NOTE: private inheritance (alternative to composition; discussed in Chapter 19)
}