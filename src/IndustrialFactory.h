#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

class IndustrialFactory : public BuildingFactory {

    private:
    protected:
    public:
    unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
