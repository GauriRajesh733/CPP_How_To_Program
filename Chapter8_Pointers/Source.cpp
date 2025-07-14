#include <iostream>

using namespace std;

int main() {
	// REVIEW: using const w pointers
	int num = int{ 5 };

	// nonconstant pointer to nonconstant data (highest access)
	int* numPtr1{ &num };
	numPtr1++; // this will work

	// constant pointer to nonconstant data
	int* const numPtr2{ &num };
	// this will not work: numPtr2++;

	// nonconstant pointer to constant data
	const int* numPtr3{ &num };
	numPtr3++;
	// this will not work: (*numPtr3)++;

	// constant pointer to constant data (least access)
	const int* const numPtr4{ &num };
	// this will not work: numPtr4++;
	// this will not work: (*numPtr4)++;


}