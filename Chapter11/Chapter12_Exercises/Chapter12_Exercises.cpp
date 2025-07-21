// Chapter12_Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "CarbonFootprint.h"
#include "Building.h"
#include "Car.h"
#include "Bicycle.h"

int main()
{
    CarbonFootprint** carbonFootprints;
    carbonFootprints = new CarbonFootprint*[3]; // allocate memory on heap

    carbonFootprints[0] = new Building(500, 30, 200);
    carbonFootprints[1] = new Bicycle(500);
    carbonFootprints[2] = new Car(500, 11.9, 2.31);

    for (int i = 0; i < 3; i++) {
        std::cout << carbonFootprints[i]->getCarbonFootprint() << std::endl;
        delete carbonFootprints[i]; // deletes each object
    }

    delete[] carbonFootprints; // deletes pointers to objects
}