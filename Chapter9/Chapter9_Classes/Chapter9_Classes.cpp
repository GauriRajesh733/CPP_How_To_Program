// Chapter9_Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time.h"
#include "CreateAndDestroy.h"
#include <array>

using namespace std;

void create(); // prototype
CreateAndDestroy first{ 1, "(global before main)" };

int main()
{
	cout << "Main Function Starts" << endl;
	Time sunset;
	array<Time, 5> arrayOfTimes;
	Time& dinnerTimeRef{ sunset }; // alias or reference to sunset time
	Time* timePtr{ &sunset }; // pointer to sunset time
	
	sunset.setTime(20, 30, 0); // 08:30PM
	cout << sunset.toStandardString() << endl;

	try {
		sunset.setTime(99, 99, 99); // invalid time
	}
	catch (const invalid_argument& e) {
		cout << "Exception: " << e.what() << endl;
	}

	// calling methods on object via pointer
	timePtr->setTime(10, 15, 0);
	cout<< timePtr->toStandardString() << endl;

	dinnerTimeRef.setHour(21);
	dinnerTimeRef.setMinute(20);
	dinnerTimeRef.setSecond(30);

	cout << sunset.toStandardString() << endl;

	// NOTE: access functions can read or display data but CANNOT MODIFY
	// can be used to test truth of conditions (predicate functions)
	// ex. testing if a list is empty

	// NOTE: utility functions or helper functions are private
	// member functions that support other functions.

	// NOTE: destructors are a special member function
	// the name of a destructor for a class is ~ (complement of constructor)
	// ex. Class(); and ~Class();
	// this method is IMPLICITLY called when an object is destroyed
	// this does ot release the object's memory, it performs
	// TERMINATION HOUSEKEEPING before its memory is reclaimed

	// NOTE: if you do not explicitly define a destructor, the compiler
	// creates an "empty" destructor

	// NOTE: destructors called when main terminates are EXIT and ABORT
	// exit forces a program to end immediately and does not execute
	// destructors of local objects
	// abort forces program to end immediately without any programmer defined
	// cleanup code to be called (usually for abnormal termination)

	// NOTE: destructors are NOT CALLED for LOCAL OBJECTS if EXIT or ABORT
	// causes program to terminate

	// NOTE: destructors called on local objects in reverse order of creation (stack)
	// NOTE: static variables exist until program terminates (ex. why sixth is deconstructed
	// after create() execution ends)

	CreateAndDestroy second{ 2, "(local in main)" };
	static CreateAndDestroy third{ 3, "(local static in main)" };

	create();

	cout << "Main Fuction Resumes" << endl;
	cout << "Main Function Ends" << endl;

	// NOTE: default memberwise or copy assignment
	// = can be used to assign an object to another object of same class

}

void create() {
	cout << "Create Fuction Starts" << endl;
	CreateAndDestroy fifth{ 5, "(local in create)" };
	static CreateAndDestroy sixth{ 6, "(local static in create)" };
	cout << "Create Fuction Ends" << endl;
}