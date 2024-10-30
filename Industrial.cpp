#include <iostream>
#include <memory> // Include for smart pointers

#include "Industrial.h"
#include "IndustrialFactory.h"
#include "Underconstruction.h"

// constructor for Industrial 
Industrial::Industrial() {
    // state of industrial building should be underconstruction
    setState(std::make_unique<Underconstruction>()); // Use smart pointer
    capacity = 20;
    buildingHealth = 100;
    price = 1000;
    runningUtils = false;
}

// builds an industrial building, calls industrial factory to create building
void Industrial::build() {
    // IndustrialFactory* newInd = new IndustrialFactory();
    // newInd->createBuilding();
    // // change building state to built here
    // std::cout << "New Industrial Building Built" << std::endl; 
}

// clones Industrial building 
// std::unique_ptr<Building> Industrial::clone() {
//     return std::make_unique<Industrial>(*this); // Return a unique_ptr<Industrial>
// }
