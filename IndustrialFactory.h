#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "Building.h"
#include "BuildingFactory.h"

class IndustrialFactory : public BuildingFactory{

    private:
    protected:
    public:
    Building* createBuilding() override;
};

#endif