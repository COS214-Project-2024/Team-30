#include <iostream>
#include "BuildingFactory.h"
#include "ResidentialFactory.h"
#include "Residential.h"

// Create a new Residential Building
unique_ptr<Building> ResidentialFactory::createBuilding() {
    std::cout << "New Residential Building is Under construction." << std::endl;
    return std::make_unique<Residential>(); // Use smart pointer to create and return a new Residential building
}
