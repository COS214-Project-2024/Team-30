#ifndef BUILDING_H
#define BUILDING_H

#include <vector>

#include "BuildingState.h"
//#include "Utilities.h"
#include "BuildingComponent.h"

class Building : public BuildingComponent{

    private:
    BuildingState*  currState;
    int capacity;
    //vector<Utilities*> utilities;
    bool runningUtils;

    protected:
    int price;

    public:
    Building(BuildingState* initialState);
    virtual void build() = 0;
    void setState(BuildingState* state); 
    void processState();
    void displayInfo();
    int buildingHealth();
    void add(BuildingComponent* component);
    void remove(BuildingComponent* component);
    void update();
    void recieveUtilities();    //Utilities
    //Utilities* setUtilities();
    virtual Building* clone() = 0;

};

#endif