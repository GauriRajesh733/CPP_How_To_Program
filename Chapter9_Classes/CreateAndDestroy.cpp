#include "CreateAndDestroy.h"
#include <iostream>
using namespace std;


CreateAndDestroy::CreateAndDestroy(int objID, string messageStr) 
	: objectID{ objID }, message{ messageStr } {
	cout << "Constructor Ran" << endl;
}

CreateAndDestroy::~CreateAndDestroy()
{
	cout << "Destructor Ran For Object " << objectID << " " << message << endl;
}

