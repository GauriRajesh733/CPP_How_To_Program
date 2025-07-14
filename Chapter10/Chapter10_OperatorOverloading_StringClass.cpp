#include <iostream>
#include "PhoneNumber.h"
#include "Date.h"
#include "Entity.h"

void printEntity(const Entity&);

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

	// NOTE: you can control ALLOCATION and DEALLOCATION of memory
	// in a program using operators NEW and DELETE

	// new -> dynamically allocate at execution time, created in
	// free store or heap, access via pointer returned by operator new

	// delete -> free store or deallocate memory so it can be used for 
	// future new operations

	// ex. obtaining dynamic memory
	// Time* timePtr{ new Time };
	// ex. releasing dynamic memory
	// delete timePtr;

	// NOTE: not releasing dynamically allocated memory when its no longer
	// needed can cause system to RUN OUT OF MEMORY
	// -> called MEMORY LEAK

	// NOTE: undefined behavior can occur if you DELETE memory that was 
	// NOT allocated by new

	// NOTE: good practice to set pointer to null after deleting so you
	// don't delete same block again (deleting nullptr has no effect)

	double* ptr{ new double{3.14159} };
	int* arr{ new int[10] }; // pointer to first elem
	delete[] arr; // call destructor for each obj in array, undefined behavior without '[]'

	// NOTE: unique_ptr is a "smart pointer"
	// -> if it goes out of scope, destructor automatically returns managed memory
	// to free store

	// CASE STUDY: array class
	// RECALL: problems with pointer-based arrays
	// -> easy to go off either side of array since cpp does not check
	// -> always 0, ..., n-1 range
	// -> entire array cannot be input or output at once
	// -> two arrays cannot be compared w equality or relational operators
	//    since array names are pointers to beginning and they obv have different 
	//    locations in memory
	// -> one built in array cannot be assigned to another with assignment ops

	// EX. custom array class

	// NOTE: use explicit keyword to avoid implicit conversions via 
	// conversion constructors

	// NOTE: can also overload cast operator functions (ex. int, string)
	// NOTE: compiler can also implicitly call these case operators to create temp objects

	// NOTE: explicit has been used so far for every constructor that can be called with one arg
	
	// NOTE: this works because of implicit conversion/construction
	Entity a("Cherno");
	Entity b = 22;

	// this also works because 22 can be converted to an Entity
	printEntity(22);
	// printEntity("Cherno"); this will not work since const char[]
	
	// this works if wrapped
	printEntity(Entity("Cherno"));

	// printEntity(string("Cherno")); this doesn't work because of explicit keyword


	// NOTE: generally avoid implicit construction, this can be prevented w EXPLICIT KEYWORD
	Entity c = 2.2;

}

void printEntity(const Entity& entity) {
}