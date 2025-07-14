// Chapter5_Exercise5.36.cpp : Extracts area code, first 3 digits, and last 4 digits 
// from input telephone number in string form (555) 555-5555 using strtok function

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    char input[15];
    char phoneNumStr[8];
    char* context = nullptr;
    int areaCode;
    long phoneNum;

    // take input phone number string
    cout << "Input a phone number in the form (555) 555-5555" << endl;
    cin.getline(input, 15);

    // extract tokens (area code, first 3 digits, last 4 digits)
    char* tokenPtr = strtok_s(input + 1, ")", &context);

    // NOTE: using atoi and atol because (int) and (long) will convert pointer address instead of string
    // convert area code string to int
    areaCode = atoi(tokenPtr);
    tokenPtr = strtok_s(NULL, "-", &context);
    strcpy_s(phoneNumStr, sizeof(phoneNumStr), tokenPtr);
    if (context != nullptr) {
        strcpy_s(phoneNumStr, sizeof(phoneNumStr), context);
    }
    else {
        cout << "Invalid phone number, missing last 4 digits";
        return 0;
    }
    // convert phone number string to long
    phoneNum = atol(phoneNumStr);

    // print area code and phone number
    cout << "Area Code: " << areaCode << endl;
    cout << "Phone Number: " << phoneNum << endl;
}