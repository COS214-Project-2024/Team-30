#ifndef BUILDINGCOMPONENT_H
#define BUILDINGCOMPONENT_H

#include "Building.h"
#include "BuildingComponent.h"

class BuildingComponent{

    private:
    Building* Building;
    //idea use a vector of type Building??

    protected:

    public:
    virtual void add(BuildingComponent* component);
    virtual void remove(BuildingComponent* component);
    virtual void displayInfo();
};

#endif