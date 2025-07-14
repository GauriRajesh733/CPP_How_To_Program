// Chapter7.1_Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

// NOTE: similar to class template arrays but support
// DYNAMIC RESIZING
    
// display vector
void outputVector(const vector<int>&);

// input values into vector
void inputVector(vector<int>&);

int main() {
    // 7 element vector<int>
    vector<int> integers1(7);
    cout << "Size of vector is: " << integers1.size();
    outputVector(integers1);

    inputVector(integers1);
    outputVector(integers1);

}

void outputVector(const vector<int>& items) {
    for (int item : items) {
        cout << item << " ";
    }
}

void inputVector(const vector<int>& items) {
    for (int item : items) {
        cin >> item;
    }
}
