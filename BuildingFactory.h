#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"

class BuildingFactory{

    private:
    protected:
    public:
    virtual Building* createBuilding() = 0;
};

#endif