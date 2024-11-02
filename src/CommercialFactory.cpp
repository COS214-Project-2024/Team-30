#include <iostream>
#include "BuildingFactory.h"
#include "CommercialFactory.h"
#include "Commercial.h"
#include <memory> // Include for smart pointers

unique_ptr<Building> CommercialFactory::createBuilding() {
    std::cout << "New Commercial Building Built" << std::endl;
    return std::make_unique<Commercial>(); // Use smart pointer
}
