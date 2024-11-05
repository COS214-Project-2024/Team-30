#include <iostream>
#include "Landmark.h"
#include "LandmarkFactory.h"
#include "Underconstruction.h"

// Constructor for Landmark
Landmark::Landmark() :Building(){
    setState(std::make_unique<Underconstruction>()); // Use smart pointer
    capacity = 100;
    buildingHealth = 90;
    price = 1500;
    runningUtils = false;
    // state of landmark building should be under construction
}

// Builds a landmark, calls landmark factory to create landmark
void Landmark::build() {
    // LandmarkFactory* newLandmark = new LandmarkFactory();
    // newLandmark->createBuilding();
    // // Change landmark state to built here
    // std::cout << "New Landmark Built" << std::endl;
}

// Clones Landmark 
unique_ptr<Building> Landmark::clone() {
    // Create a new Landmark instance
    auto clonedLandmark = std::make_unique<Landmark>();

    clonedLandmark->capacity = this->capacity;
    clonedLandmark->buildingHealth = this->buildingHealth;
    clonedLandmark->price = this->price;
    clonedLandmark->runningUtils = this->runningUtils;

    if (this->currState) {
        clonedLandmark->currState = this->currState->clone();
    }

    return clonedLandmark;
}

string Landmark::getType()
{
    return "Landmark Building";
}