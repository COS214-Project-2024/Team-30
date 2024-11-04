#include <iostream>
#include "Residential.h"
#include "ResidentialFactory.h"
#include "Underconstruction.h"

// Creates a Residential object
Residential::Residential() : Building(){
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
unique_ptr<Building> Residential::clone() {
    // Create a new Residential instance
    auto clonedResidential = std::make_unique<Residential>();

    clonedResidential->capacity = this->capacity;
    clonedResidential->buildingHealth = this->buildingHealth;
    clonedResidential->price = this->price;
    clonedResidential->runningUtils = this->runningUtils;

    if (this->currState) {
        clonedResidential->currState = this->currState->clone();
    }

    return clonedResidential;
}

string Residential::getType()
{
    return "Residential Building";
}
