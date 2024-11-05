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
    /**
     * @brief Virtual destructor for BuildingFactory.
     */
    virtual ~BuildingFactory();

protected:
    /**
     * @brief Creates a new Building object.
     *
     * This is a pure virtual function that must be implemented by derived classes
     * to create instances of specific building types.
     * @return A unique pointer to a newly created Building object.
     */
    virtual unique_ptr<Building> createBuilding() = 0;
};

#endif
