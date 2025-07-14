// Chapter7_Arrays_Vectors_CatchingExceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "max.h";
using std::cout;
using std::endl;
int x{ 1 }; // global scope var


// NOTE: inline functions
// def appears before function called so no need for prototype
// compilers can inline code without explicit keyword, best to leave
// this to compiler
inline double cube(const double side) {
	return side * side * side;
}

// NOTE: functions w default values
void hi(int h = 1, int i = 1) {
	cout << h << i;
}


int main()
{
	// NOTE: functions like main are NOT members of a class
	// they are called GLOBAL FUNCTIONS

	// RECALL: function prototypes tell the compiler the functions name,
	// return type, and types of params (param names are ignored)

	// RECALL: enum class
	enum class Months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

	// NOTE: can also specify type of enum constants (opt)
	
	// scoped
	enum class Status : unsigned int {CONTINUE, WON, LOST};

	// unscoped
	enum COLOR {RED, GREEN, BLUE};
	
	// NOTE: scope
	cout << x << endl; // 1

	int x = 5;
	cout << x << endl; // 5


	// block starts new scope
	{
		int x = 7;
		cout << x << endl; // 7
	}

	cout << x << endl; // 5

	double cube3 = cube(3);

	// RECALL: pass by reference (security) vs pass by value (issue: copying large vals)
	// use const reference param for large objects for security of pass by value
	// and avoid copying like in pass by reference

	// NOTE: :: or unary scope resolution operator is used to access a global variable when 
	// a local var w SAME NAME is in scope (not for outer block)
	// generally good practice to use ::

	// RECALL: function overloading
	// compiler chooses appropriate function to call based on type of arg (similar to Java)
	// compiler differentiates based on SIGNATURES (func name, params in order)
	// this is known as NAME MANGLING or NAME DECORATION to enable TYPE SAFE LINKAGE

	cout << max(3, 4) << endl;
	cout << max(5.9, 2.1) << endl;

	// RECALL: recursion (base case(s), recursive call/step)
	// RECALL: ex. factorial BUT exponential calls!




}
