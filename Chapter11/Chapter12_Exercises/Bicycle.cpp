#include "Bicycle.h"

Bicycle::Bicycle(double distance)
{
	this->distance = distance;
}

std::string Bicycle::getCarbonFootprint()
{
	return "Carbon Footprint of Bicycle: " + std::to_string(0.05 * distance) + " kg CO2e\n";
}
