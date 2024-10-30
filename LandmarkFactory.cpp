#include <iostream>
#include "BuildingFactory.h"
#include "Landmark.h"
#include "LandmarkFactory.h"

// Create a new Landmark Building
std::unique_ptr<Building> LandmarkFactory::createBuilding() {
    std::cout << "New Landmark Made" << std::endl;
    return std::make_unique<Landmark>(); // Use smart pointer to create and return a new Landmark
}
