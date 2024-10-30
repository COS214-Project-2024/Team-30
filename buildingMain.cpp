#include <iostream>
#include <memory> // Include for smart pointers
#include "Building.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "Underconstruction.h"
#include "Built.h"
#include "Destroyed.h"

int main() {
    // Create factories
    ResidentialFactory residentialFactory;
    CommercialFactory commercialFactory;
    IndustrialFactory industrialFactory;
    LandmarkFactory landmarkFactory;

    // Create buildings using factories with smart pointers
    std::unique_ptr<Building> residentialBuilding = residentialFactory.createBuilding();
    std::unique_ptr<Building> commercialBuilding = commercialFactory.createBuilding();
    std::unique_ptr<Building> industrialBuilding = industrialFactory.createBuilding();
    std::unique_ptr<Building> landmarkBuilding = landmarkFactory.createBuilding();

    // Display the initial state of each building
    std::cout << "Residential Building State: " << residentialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Commercial Building State: " << commercialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Industrial Building State: " << industrialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Landmark Building State: " << landmarkBuilding->getState()->getStatus() << std::endl;

    // Simulate building completion by changing the state
    residentialBuilding->setState(std::make_unique<Built>());
    commercialBuilding->setState(std::make_unique<Built>());
    industrialBuilding->setState(std::make_unique<Built>());
    landmarkBuilding->setState(std::make_unique<Built>());

    // Display the state after construction is complete
    std::cout << "Residential Building State after build: " << residentialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Commercial Building State after build: " << commercialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Industrial Building State after build: " << industrialBuilding->getState()->getStatus() << std::endl;
    std::cout << "Landmark Building State after build: " << landmarkBuilding->getState()->getStatus() << std::endl;

    // No need for manual cleanup due to smart pointers
    return 0;
}
