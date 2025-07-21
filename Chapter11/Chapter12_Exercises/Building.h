#pragma once
#include "CarbonFootprint.h"
class Building :
    public CarbonFootprint
{
public:
    Building(double, double, double);
    std::string getCarbonFootprint() override;
private:
    double embodiedCarbon;
    double operationalCarbon;
    double carbonSequestration;
};

