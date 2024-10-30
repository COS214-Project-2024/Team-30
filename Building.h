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
    int price; //? whats price

    public:
    Building(); //Building constructor
    Building(BuildingState* initialState); //set state to underconstruction
    virtual void build() = 0;

    void setState(BuildingState* state); //set state to underconstruction
    void processState(); //request() function for State DP
    
    void displayInfo() override;

    int buildingHealth(); 

    void add(BuildingComponent* component) override;
    void remove(BuildingComponent* component) override;
    void update();

    void recieveUtilities();    //Utilities
    //Utilities* setUtilities();

    virtual Building* clone() = 0;

};

#endif