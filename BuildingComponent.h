#ifndef BUILDINGCOMPONENT_H
#define BUILDINGCOMPONENT_H

#include "Building.h"
#include "BuildingComponent.h"

class BuildingComponent{

    private:
    Building* Building;

    protected:
    public:
    void add(BuildingComponent* component);
    void remove(BuildingComponent* component);
    virtual void displayInfo();
};

#endif