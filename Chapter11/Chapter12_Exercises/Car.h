#pragma once
#include "CarbonFootprint.h"
class Car :
    public CarbonFootprint
{
public:
    Car(double = 0, double = 16.5, double = 4.6);
    std::string getCarbonFootprint() override;

private:
    double distance;
    double fuelEfficiency;
    double emissionsFactor;
};

