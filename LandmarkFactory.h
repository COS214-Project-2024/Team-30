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
    unique_ptr<Building> createBuilding() override; // Change to return unique_ptr<Building>
};

#endif
