#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

/**
 * @class CommercialFactory
 * @brief Factory class for creating Commercial Building objects.
 *
 * The CommercialFactory class implements the BuildingFactory interface to create instances of commercial buildings.
 */

class CommercialFactory : public BuildingFactory {
    public:
    /**
     * @brief Creates a new Commercial Building object.
     *
     * Overrides the createBuilding method to create an instance of a commercial building.
     * @return A unique pointer to a newly created commercial Building object.
     */
    unique_ptr<Building> createBuilding() override; // Change return type to unique_ptr<Building>
};

#endif
