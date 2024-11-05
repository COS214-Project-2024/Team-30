#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory> // Include for smart pointers
#include <algorithm>
#include "BuildingState.h"
// #include "Utilities.h"
// #include "BuildingComponent.h"
#include "Emergencies.h"
#include "Citizen.h"

#include "Coal.h"
#include "Water.h"
#include "Road.h"

// #include "Utilities.h"

class Emergencies;
class Utilities;
class Road;


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
    shared_ptr<Road> road;

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
    void update();

    // Utilities* setUtilities();

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void notifyCitizensOfEmergency(int damage);


    void setUtilities();
    
    void setWater(int water);
    void setPower(int power);
    void setSewerage(int sewerage);
    void setWaste(int waste);

    int getWater();
    int getPower();
    int getSewerage();
    int getWaste();

    void receiveWater(int);
    void receiveElectricity(int);
    void receiveUtilities(shared_ptr<Coal> c, shared_ptr<Water> w);
    void checkConstructionStatus();
    std::vector<std::shared_ptr<Citizen>>& getResidents() ;


    virtual unique_ptr<Building> clone() = 0; // Return unique_ptr
    void setRoad(shared_ptr<Road> road);
    shared_ptr<Road> getRoad();
};

#endif
