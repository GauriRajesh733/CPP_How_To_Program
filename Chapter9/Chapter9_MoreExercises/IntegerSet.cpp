#include "IntegerSet.h"
#include <iostream>

using namespace std;


IntegerSet::IntegerSet() : set(101, false) {
}

// return union of this set and other given set
IntegerSet IntegerSet::unionOfSets(IntegerSet other)
{
	IntegerSet setUnion;

	for (int i = 0; i < 101; i++) {
		if (contains(i) && other.contains(i)) {
			setUnion.add(i);
		}
	}

	return setUnion;
}

	// does this set contain the given number
bool IntegerSet::contains(int n) {
	return set[n];
}

// add to this set
void IntegerSet::add(int n) {
	if (n < 0 || n > 100) {
		throw invalid_argument("number must be between 0 and 100 inclusive");
	}
	set[n] = true;
}

// display all numbers in this set
void IntegerSet::displaySet() {
	cout << "Elements in Set: ";
	for (int i = 0; i < 101; i++) {
		if (set[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}

bool IntegerSet::containsSet(IntegerSet other) {
	for (int i = 0; i < 101; i++) {
		if (other.contains(i) && !contains(i)) {
			return false;
		}
	}
	return true;
}

bool IntegerSet::sameSet(IntegerSet other) {
	return containsSet(other) && other.containsSet(*this);
}
