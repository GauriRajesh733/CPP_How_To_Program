// Chapter12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // RECALL: virtual function keyword used to override methods
    // in derived classes and enable polymorphic behavior

    // NOTE: invoking virtual function through base class pointer or reference
    // program chooses chorrect derived class function DYNAMICALLY based
    // on OBJECT TYPE, not POINTER OR REFERENCE TYPE (dynamic binding)

    // NOTE: invoking virtual function through object's name using "." notation
    // is static binding (NOT POLYMORPHIC)

    // NOTE: virtual destructors
    // if DERIVED class object with NON-VIRTUAL DESTRUCTOR is 
    // destroyed using DELETE, BEHAVIOR IS UNDEFINED
    // -> SOLUTION: create public virtual destructor in base class
    //    this allows for correct destructor to be called (base class destructors 
    //    automatically called after derived class destructor)

    // NOTE: virtual func(params) final CANNOT BE OVERRIDDEN

    // RECALL: can sometimes avoid having to type check due to polymorphic behavior

    // RECALL: abstract vs concrete classes
    // -> class made ABSTRACT by declaring 1+ functions as PURE VIRTUAL FUNCTIONS
    // ex. virtual void draw() const = 0;

    // RECALL: abstract functions or pure virtual functions REQUIRE
    // derived classes CREATE IMPLEMENTATIONS

    // NOTE: Polymorphism "Under the Hood"
    // -> uses three levels of pointers (triple indirection)
    //    -> function pointers in vtable, pointer to vtable for class,
    //       and handles to objects that recieve virtual function calls (can also be references)
    // -> if class has 1+ virtual functions, cpp builds virtual function
    //    table or vtable
    // -> vtable contains pointers to class's virtual functions or pointer to
    //    starting address of function code in memory
    // ex. initially pure virtual function pointer is set to 0 or nullptr
}

