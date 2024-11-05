#include <iostream>
#include <memory> // Include for smart pointers

#include "Industrial.h"
#include "IndustrialFactory.h"
#include "Underconstruction.h"

// constructor for Industrial 
Industrial::Industrial() :Building(){
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
unique_ptr<Building> Industrial::clone() {
    // Create a new Industrial instance
    auto clonedIndustrial = std::make_unique<Industrial>();

    clonedIndustrial->capacity = this->capacity;
    clonedIndustrial->buildingHealth = this->buildingHealth;
    clonedIndustrial->price = this->price;
    clonedIndustrial->runningUtils = this->runningUtils;

    if (this->currState) {
        clonedIndustrial->currState = this->currState->clone();
    }

    return clonedIndustrial;
}

string Industrial::getType()
{
    return "Industrial Building";
}