#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

class BuildingFactory
{

private:
    Building *building;

public:
    virtual ~BuildingFactory();

protected:
    virtual unique_ptr<Building> createBuilding() = 0;
};

#endif