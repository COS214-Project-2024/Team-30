#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory>  // Include for smart pointers

#include "BuildingState.h"
//#include "Utilities.h"
#include "BuildingComponent.h"
using namespace std;

// : public BuildingComponent
class Building {
    protected:
    //vector<Utilities*> utilities;
    unique_ptr<BuildingState> currState; // Use unique_ptr for ownership
    int capacity; 
    int buildingHealth;
    int price; //? whats price : price is gonna work with city budget in government
    bool runningUtils;

    public:
    // Building(); //Building constructor
    // Building(BuildingState* initialState); //set state to underconstruction
    virtual ~Building();
    virtual void build() = 0;
    BuildingState* getState();
    void setState(unique_ptr<BuildingState> state); // Accept a unique_ptr
    void processState(); //request() function for State DP
    
    void displayInfo(); //removed override keyword. testing without the building component

    //removed Building health, changed to member variable
    
    // void add(BuildingComponent* component) override;
    // void remove(BuildingComponent* component) override;

    void update();
    void recieveUtilities();    //Utilities
    //Utilities* setUtilities();

    // virtual unique_ptr<Building> clone() = 0; // Return unique_ptr

};

#endif
