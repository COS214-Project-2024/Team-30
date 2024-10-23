#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"

class CommercialFactory : public BuildingFactory{

    private:
    protected:
    public:
    Building* createBuilding();
};

#endif