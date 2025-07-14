// 10.9_DynamicMemoryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

int main()
{
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



}
