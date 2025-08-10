#include <iostream>
#include <vector>
#include "CustomAllocator.h"
#include <algorithm>



int main()
{
	// Custom Allocator Example

	CustomAllocator c1(9);

	// data smaller than tracked data slot, need to split
	char* d = c1.allocateMemory<char>('d');
	c1.displayMemory();
	
	// data fits perfectly into a tracked data slot
	int* one = c1.allocateMemory<int>(1);
	c1.displayMemory();
	

	int* two = c1.allocateMemory<int>(2);
	c1.displayMemory();
	

	// data fits into combined slot
	c1.freeMemory(one);	
	c1.displayMemory();

	c1.freeMemory(two);
	c1.displayMemory();


	double* pi = c1.allocateMemory<double>(3.14);
	c1.displayMemory();
	

	// not enough continuous space to store data
	char* p = c1.allocateMemory<char>('p');
	c1.displayMemory();
	

	



}