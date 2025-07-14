// Chapter5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

int main()
{
    // FUNCTION POINTERS

    // EXAMPLE 1
    void function1(int n);
    void function2(int n);
    void function3(int n);

    // func is an array of 3 pointers to function that take in 1 integer and have a void result
    void (*func[3]) (int) = { function1, function2, function3 };
    int choice, num;

    cout << "Enter a number between 0 and 2, 3 to end: " << endl;
    cin >> choice;

    while (choice == 0 || choice == 1 || choice == 2) {
        cout << "Enter a number" << endl;
        cin >> num;
        // select pointer, dereference, and pass in arg
        (*func[choice])(num);

        cout << "Enter a number between 0 and 2, 3 to end: " << endl;
        cin >> choice;
    }

    // CHARACTER AND STRING PROCESSING

    // strings are ARRAYS of CHARS; constant pointer to first character (similar to arrays)
    // array ends with null character '\0'
    
    // 2 ways to declare
    char color[] = "blue";
    const char *colorPtr = "blue";
    
    string input;
    const char* word;
    cout << "Enter text: " << endl;
    cin >> setw(10) >> input;
    word = input.c_str();
    while (*word != '\0') {
        cout << *word << endl;
        word++;
    }

    // STRING HANDLING LIBRARY FUNCTIONS

    const char* x = "happy birthday";
    char y[15], z[4];
    
    // strncpy
    strncpy_s(y, 15, x, 15);
    strncpy_s(z, 4, x, 3);
    cout << "the string in y is " << y << endl;
    cout << "the string in z is " << z << endl;

    // strcat
    char w[20] = "";
    strcat_s(w, y);
    strcat_s(w, z);
    cout << "the string in w is " << w << endl;

    // strcmp
    cout << strcmp(w, w);
    cout << strcmp(w, y);

    // strncmp
    cout << strncmp(w, y, sizeof(y));

    // strtok
    char* context = nullptr;
    cout << strtok_s(w,"p", &context);
    cout << strtok_s(NULL, "\0", &context);


    // strlen

}

void function1(int n) {
    cout << "You entered " << n << "." << endl;
    cout << n << " X 1 = " << n << endl;
}

void function2(int n) {
    cout << "You entered " << n << "." << endl;
    cout << n << " X 2 = " << (n * 2) << endl;
}

void function3(int n) {
    cout << "You entered " << n << "." << endl;
    cout << n << " X 3 = " << (n * 3) << endl;
}
    

