#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"

class LandmarkFactory : public BuildingFactory{

    private:
    protected:
    public:
    Building* createBuilding();
};

#endif