#include <iostream>
#include "Landmark.h"
#include "LandmarkFactory.h"
#include "Underconstruction.h"

// Constructor for Landmark
Landmark::Landmark() {
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
// std::unique_ptr<Building> Landmark::clone() {
//     return std::make_unique<Landmark>(*this); // Return a unique_ptr<Landmark>
// }
