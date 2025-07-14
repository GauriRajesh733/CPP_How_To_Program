#pragma once
#include <iostream>
#include <string>

using namespace std;

class PhoneNumber
{
	// NOTE: these cannot be member functions
	// if you want to invoke them like cout << instead
	// of phone << cout; or phone >> cin;

	// NOTE: friend functions access private class members for performance
	// or because class does not have appropriate get functions
	friend ostream& operator<<(ostream&, const PhoneNumber&);

	friend istream& operator>>(istream&, PhoneNumber&);

	// overloading unary operator as member function
public:
	bool operator!() const {
		cout << "! operator called on phone number." << endl;
		return true;
	}
private:
	string areaCode;  // area code
	string exchange; // exchange
	string line; // line
};

