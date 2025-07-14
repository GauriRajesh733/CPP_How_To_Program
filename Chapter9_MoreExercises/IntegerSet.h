#pragma once
#include <vector>
#include <stdexcept>

using namespace std;

// Integer Set class can hold integers 
// in the range 0 to 100.  The set field 
// stores boolean values based on whether 
// the integer with that index exists in 
// the set.

class IntegerSet
{
public:
	IntegerSet();

	IntegerSet unionOfSets(IntegerSet);

	bool contains(int n);

	void add(int n);

	void displaySet();

	bool sameSet(IntegerSet);

	bool containsSet(IntegerSet);
private:
	vector<bool> set;
};

