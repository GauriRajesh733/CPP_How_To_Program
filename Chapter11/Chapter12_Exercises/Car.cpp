#include "Car.h"


Car::Car(double distance, double fuelEfficiency, double emissionsFactor)
{
	this->distance = distance;
	this->fuelEfficiency = fuelEfficiency;
	this->emissionsFactor = emissionsFactor;
}

std::string Car::getCarbonFootprint()
{
	return "Carbon Footprint of Car: " + std::to_string(distance / fuelEfficiency * emissionsFactor) + " kg CO2e\n";
}