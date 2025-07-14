// Chapter1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Gauri's first C++ program on Visual Studio\n";

    // practice exercises

    // declare integer variables
    int c, thisIsAVariable, q76354, number;

    // prompt user to enter integer
    std::cout << "Please enter an integer: ";
    std::cin >> number;
    if (number != 7) {
        std::cout << "The variable number is not equal to 7.\n";
    }
    else {
        std::cout << "The variable number is equal to 7.\n";
    }

    // display text on separate lines
    std::cout << "This is on\ntwo lines";
}
