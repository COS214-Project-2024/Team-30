#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

class ResidentialFactory : public BuildingFactory {

    private:
    protected:
    public:
    std::unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
