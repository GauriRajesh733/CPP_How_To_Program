#include "Building.h"

Building::Building(double embodiedCarbon, double operationalCarbon, double carbonSequestration)
{
    this->embodiedCarbon = embodiedCarbon;
    this->operationalCarbon = operationalCarbon;
    this->carbonSequestration = carbonSequestration;
}

std::string Building::getCarbonFootprint()
{
    return "Carbon Footprint of Building: " + std::to_string(embodiedCarbon + operationalCarbon - carbonSequestration) + " kg CO2e \n";
}
