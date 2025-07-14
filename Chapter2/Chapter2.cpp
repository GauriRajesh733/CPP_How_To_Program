// Chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	// if, if else, while, for are same as in Java

	// casting
	double before;
	std::cout << "Enter a double: ";
	std::cin >> before;
	int after;
	after = static_cast<int>(before);
	std::cout << after;
}
