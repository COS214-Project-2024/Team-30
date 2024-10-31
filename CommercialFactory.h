#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

class CommercialFactory : public BuildingFactory {
    public:
    unique_ptr<Building> createBuilding() override; // Change return type to unique_ptr<Building>
};

#endif
