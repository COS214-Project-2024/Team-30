#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

/**
 * @class ResidentialFactory
 * @brief Factory class for creating Residential Building objects.
 *
 * The ResidentialFactory class implements the BuildingFactory interface to create instances of residential buildings.
 */

class ResidentialFactory : public BuildingFactory {

    private:
    protected:
    public:
    /**
     * @brief Creates a new Residential Building object.
     *
     * Overrides the createBuilding method to create an instance of a residential building.
     * @return A unique pointer to a newly created residential Building object.
     */
    unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
