#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include "Building.h"

class BuildingState{

    private:
    protected:
    Building* building;

    public:
    virtual ~BuildingState(){};

    void setBuilding(Building* currbuilding); 
    void setState();

    virtual void handle() = 0;
    virtual void changeState() = 0;
};

#endif