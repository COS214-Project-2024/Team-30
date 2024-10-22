#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"

class ResidentialFactory : public BuildingFactory{

    private:
    protected:
    public:
    Building* createBuilding();
};

#endif