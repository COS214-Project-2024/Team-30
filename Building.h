#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory> // Include for smart pointers
#include <algorithm>
#include "BuildingState.h"
// #include "Utilities.h"
#include "BuildingComponent.h"
#include "Emergencies.h"
#include "Citizen.h"
#include "Utilities.h"
#include "Resource.h"
#include "Coal.h"
#include "Water.h"

class Emergencies;

using namespace std;
//
class Building : public std::enable_shared_from_this<Building> 
//  : public BuildingComponent
{
protected:
    // vector<Utilities*> utilities;
    int id;
    unique_ptr<BuildingState> currState; // Use unique_ptr for ownership
    int capacity;
    int buildingHealth;
    int price; //? whats price : price is gonna work with city budget in government
    bool runningUtils;
    vector<shared_ptr<Citizen>> residents;
    static int nextID;
    std::unique_ptr<Utilities> utils;


    //Utilities
    int water;
    int power;
    int waste;
    int sewerage;


public:
    Building(); //Building constructor
    // Building(BuildingState* initialState); //set state to underconstruction
    virtual ~Building();
    int getCapacity();
    virtual void build() = 0;
    BuildingState *getState();
    void setState(unique_ptr<BuildingState> state); // Accept a unique_ptr
    void setCapacity(int capacity);
    void processState(); // request() function for State DP
    virtual string getType() = 0;
    void displayInfo(); // removed override keyword. testing without the building component
    void simulateEmergency(Emergencies &emergency);
    bool hasOccupant(int citizenID) const;
    void printResidents();
    bool containsCitizen(shared_ptr<Citizen> citizen);
    int getID();
    // void add(std::unique_ptr<BuildingComponent> component) override;
    // void remove(std::unique_ptr<BuildingComponent> component) override;
    void takeDamage(int damage);

    void receiveUtilities(Coal* c, Water* w); // Utilities
    void receiveWater(int);
    void receiveElectricity(int);
    void receiveUtilities(Coal* c, Water* w);
    void checkConstructionStatus();
    // Utilities* setUtilities();

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void notifyCitizensOfEmergency(int damage);


    void setUtilities();
    
    void setWater(int water);
    void setPower(int power);
    void setSewage(int sewerage);
    void setWaste(int waste);

    int getWater();
    int getPower();
    int getSewerage();
    int getWaste();

    virtual unique_ptr<Building> clone() = 0; // Return unique_ptr
};

#endif
