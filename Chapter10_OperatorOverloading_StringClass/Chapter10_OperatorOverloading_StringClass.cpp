#include <iostream>
#include "PhoneNumber.h"
#include "Date.h"

int main()
{
	// ex. + and - perform differently depending
	// on data type

	// ex. >> is used as a stream extraction operator
	// and bitwise right-shift operator

	// NOTE: operators you don't have to overload
	// =, &, and ,

	// NOTE: ., ::, ?:, .* cannot be overloaded

	// NOTE: only existing operators can be overloaded with keyword

	// EX. overloading binary stream insertion and stream extraction

	PhoneNumber phone;

	//cout << "Enter phone number in form (555) 555-5555:" << endl;
	// implicit call to operator>>(cin, phone)
	//cin >> phone;
	// implicit call to operator<<(cout, phone)
	//cout << phone << endl;

	// EX. overloading unary operators
	//!phone;

	// EX. date class

	// changing days and month
	Date d1(10, 28, 2005);
	cout << d1;

	for (int i = 0; i < 30; i++) {
		d1++;
		cout << d1;
	}

	// changing year
	Date d2(12, 30, 2015);
	for (int i = 0; i < 30; i++) {
		d2++;
		cout << d2;
	}

}