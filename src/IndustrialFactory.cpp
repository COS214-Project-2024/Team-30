// Create a new Industrial Building
#include <iostream>
#include "BuildingFactory.h"
#include "IndustrialFactory.h"
#include "Industrial.h"

// Create a new Industrial Building
unique_ptr<Building> IndustrialFactory::createBuilding() {
    std::cout << "New Industrial Building Built." << std::endl;
    return std::make_unique<Industrial>(); // Create and return a unique_ptr<Industrial>
}

