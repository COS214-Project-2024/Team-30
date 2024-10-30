#include <iostream>
#include "Residential.h"
#include "ResidentialFactory.h"
#include "Underconstruction.h"

// Creates a Residential object
Residential::Residential() {
    // State of residential building should be under construction
    setState(std::make_unique<Underconstruction>()); // Use smart pointer
    capacity = 4;
    buildingHealth = 100;
    price = 500;
    runningUtils = false;
}

// Builds a residential building, calls residential factory to create building
void Residential::build() {
    // ResidentialFactory* newRes = new ResidentialFactory();
    // newRes->createBuilding();
    // // Change building state to built here
    // std::cout << "New Residential Building Built" << std::endl;
}

// Clones Residential building
// std::unique_ptr<Building> Residential::clone() {
//     return std::make_unique<Residential>(*this); // Use smart pointer for cloning
// }
