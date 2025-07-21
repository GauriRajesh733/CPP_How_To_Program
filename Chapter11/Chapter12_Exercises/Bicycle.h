#pragma once
#include "CarbonFootprint.h"
class Bicycle :
    public CarbonFootprint
{
public:
    Bicycle(double = 0.0);
    std::string getCarbonFootprint() override;

private:
    double distance;
};

