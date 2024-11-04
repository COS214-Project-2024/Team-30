#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

/**
 * @class BuildingFactory
 * @brief Abstract factory class for creating Building objects.
 *
 * The BuildingFactory class provides an interface for creating different types of buildings.
 * Derived factory classes must implement the createBuilding method to instantiate specific building types.
 */

class BuildingFactory
{
public:
    virtual ~BuildingFactory();

protected:
    virtual unique_ptr<Building> createBuilding() = 0;
};

#endif
