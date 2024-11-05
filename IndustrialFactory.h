#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

/**
 * @class IndustrialFactory
 * @brief Factory class for creating Industrial Building objects.
 *
 * The IndustrialFactory class implements the BuildingFactory interface to create instances of industrial buildings.
 */

class IndustrialFactory : public BuildingFactory {

    private:
    protected:
    public:
    /**
     * @brief Creates a new Industrial Building object.
     *
     * Overrides the createBuilding method to create an instance of an industrial building.
     * @return A unique pointer to a newly created industrial Building object.
     */
    unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
