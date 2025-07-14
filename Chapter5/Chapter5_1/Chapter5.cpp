// Chapter5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;



int main()
{
    void bubbleSort(int*, const int);

    // pointer variable declarations and initialization

    // ex. countPtr is a pointer to an integer and count is an integer
    int *countPtr = nullptr, count;

    if (countPtr) {
        cout << "pointer has been assigned to " << countPtr << endl;
    }
    else {
        cout << "pointer has not been assigned yet" << endl;
    }

    count = 5;

    // countPtr points to address of count variable
    countPtr = &count;

    if (countPtr) {
        cout << "pointer has been assigned to " << countPtr << " with value " << count << endl;
    }
    else {
        cout << "pointer has not been assigned yet" << endl;
    }

    // indirection operator *

    // gets alias or synonym for value
    cout << *countPtr << endl;

    // assign new value to y
    *countPtr = 9;

    cout << count << endl;

    // REVIEW: function prototype
    // declaration with signature of function before actual definition
    // in case function is called first
    // also used in header files to make functions accessible across 
    // multiple source files without redefining

    // const qualifier: variable cannot be modified

    // 4 ways to pass pointer to function w/ different levels of access privileges
    // nonconstant pointer to nonconstant data (highest access), nonconstant pointer to constant data, 
    // constant pointer to nonconstant data, constant pointer to constant data (least access)

    // bubble sort example
    const int arraySize = 10;
    int a[arraySize] = { 2,6,4,8,10,12,89,68,45,37 };
    int i;

    for (i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    bubbleSort(a, arraySize);

    for (i = 0; i < arraySize; i++)
        cout << setw(4) << a[i];

    cout << endl;

    // NOTE: sizeof can be applied to any variable name, type name, or constant value
    cout << "size of countPtr: " << sizeof(countPtr) << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of long: " << sizeof(long) << endl;

    // pointer arithmetic (if pointer refers to array of values)
    // can perform basic addition and subtraction w integers and other pointers (if same array!)
    // NOTE: pointer arithmetic is machine dependent since size of objects depends on computer systems
    // example: ptr += 2 -> ptr += 2*4 since integer stored as 4 bytes in memory
    // ++ and -- to increment or decrement by 1

    // NOTE: arrays and pointers are closely related in C++!
    // array name is constant pointer and pointers can do operations related to array subscripting
    // array name ALWAYS points to beginning of array so CANNOT perform POINTER ARITHMETIC

    // Strings are POINTERS to FIRST CHAR
    const char* suit[4] = { "hearts", "diamonds", "spades", "clubs"};

    // function pointers contain address of function in memory
    // function name is STARTING ADDRESS in memory of CODE THAT PERFORMS FUNCTION similar to array name
    
    // example: expect pointer to function that takes in two integers and returns a boolean value
    // NOTE: can add input names as well, compiler will just ignore
    void bubble2(int work[], const int size, bool (*compare) (int, int));

    return 0;
}

// NOTE: good practice to pass in size of array as well
// sizeof unary operator returns number of bytes in array which can depend on computer system
void bubbleSort(int* array, const int size) {
    void swap(int* const, int* const);

    for (int pass = 0; pass < size - 1; pass++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void swap(int* const elem1Ptr, int* const elem2Ptr) {
    int hold = *elem1Ptr;
    *elem1Ptr = *elem2Ptr;
    *elem2Ptr = hold;
}