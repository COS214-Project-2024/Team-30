#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"
#include <memory> // Include for smart pointers

/**
 * @class LandmarkFactory
 * @brief Factory class for creating Landmark Building objects.
 *
 * The LandmarkFactory class implements the BuildingFactory interface to create instances of landmark buildings.
 */

class LandmarkFactory : public BuildingFactory {

    private:
    protected:
    
    public:
     /**
     * @brief Creates a new Landmark Building object.
     *
     * Overrides the createBuilding method to create an instance of a landmark building.
     * @return A unique pointer to a newly created landmark Building object.
     */
    unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
