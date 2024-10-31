#include <iostream>
#include <memory> // Include for smart pointers

#include "Commercial.h"
#include "CommercialFactory.h"
#include "Underconstruction.h"

// constructor for Commercial
Commercial::Commercial()
{
    // initial state of Commercial Building should be Underconstruction
    setState(make_unique<Underconstruction>()); // Use smart pointer
    capacity = 20;
    buildingHealth = 100;
    price = 1200;
    runningUtils = false;
}

// builds a Commercial building, calls Commercial Factory to create building
void Commercial::build() {
    // CommercialFactory* newComm = new CommercialFactory();
    // newComm->createBuilding();
    // // change state to built here
    // std::cout << "New Commercial Building Built" << std::endl;

}

// clones a Commercial Building
unique_ptr<Building> Commercial::clone() {
    // Create a new Commercial instance
    auto clonedCommercial = std::make_unique<Commercial>();

    clonedCommercial->capacity = this->capacity;
    clonedCommercial->buildingHealth = this->buildingHealth;
    clonedCommercial->price = this->price;
    clonedCommercial->runningUtils = this->runningUtils;

    if (this->currState) {
        clonedCommercial->currState = this->currState->clone();
    }

    return clonedCommercial;
}

string Commercial::getType()
{
    return "Commercial Building";
}
