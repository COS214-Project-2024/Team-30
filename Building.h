#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <algorithm>
#include <memory>  // Include for smart pointers

#include "BuildingState.h"
//#include "Utilities.h"
#include "BuildingComponent.h"
using namespace std;


class Building : public BuildingComponent{
    protected:
    //string name;
    int capacity; 
    int buildingHealth;
    int price; //price is gonna work with city budget in government
    bool runningUtils;
    std::unique_ptr<BuildingState> currState; // Use unique_ptr for ownership

    //Utilities
    // int water;
    // int power;
    // int waste;
    // int sewerage;

    public:
    Building();
    //Building(const std::string& name);        composite constructor
    virtual ~Building();
    virtual void build() = 0;
    BuildingState* getState();
    void setState(unique_ptr<BuildingState> state); 
    void processState();    
    void displayInfo();
    void update();  
    virtual unique_ptr<Building> clone() = 0; 
    //void showInfo() const override;
    // void setUtilities();
    // void requestUtilities();

};

#endif
