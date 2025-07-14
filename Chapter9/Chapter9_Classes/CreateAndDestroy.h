#pragma once
#include <string>

#ifndef CREATE_H
#define CREATE_H

using namespace std;

class CreateAndDestroy
{
public:
	CreateAndDestroy(int, string); // constructor
	~CreateAndDestroy(); // destructor
	// NOTE: VERY DANGEROUS to return reference to private field
	// ex. int& badSetID(int);

private:
	int objectID;
	string message;
};

#endif

