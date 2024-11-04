#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <algorithm>
#include <memory>  // Include for smart pointers

#include "BuildingState.h"
#include "Utilities.h"
#include "BuildingComponent.h"
#include "Citizen.h"
#include "Emergencies.h"

using namespace std;

class Emergencies;

class Building : public BuildingComponent{
    protected:
    std::string name;
    int capacity; 
    int buildingHealth;
    int price; //price is gonna work with city budget in government
    bool runningUtils;
    std::unique_ptr<BuildingState> currState; // Use unique_ptr for ownership

    vector<shared_ptr<Citizen>> residents;

    //Utilities
    int water;
    int power;
    int waste;
    int sewerage;

    public:
    //Building();
    //Building(const std::string& name);        //composite constructor
    virtual ~Building();
    int getCapacity();
    virtual std::string getType() = 0;
    virtual void build() = 0;
    BuildingState* getState();
    void setState(unique_ptr<BuildingState> state); // Accept a unique_ptr
    void processState();    
    void displayInfo();
    void update();  
    virtual unique_ptr<Building> clone() = 0; 
    void showInfo() const override; //composite

    void setUtilities();
    void requestUtilities();
    
    void setWater(int water);
    void setPower(int power);
    void setSewerage(int sewerage);
    void setWaste(int waste);

    int getWater();
    int getPower();
    int getSewerage();
    int getWaste();

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void notifyCitizensOfEmergency(int damage);

    void simulateEmergency(Emergencies &emergency);
    bool hasOccupant(int citizenID) const;

    void simulateEmergency(Emergencies &emergency);
    bool hasOccupant(int citizenID) const;

    void printResidents();
    string getName();
    bool containsCitizen(shared_ptr<Citizen> citizen);

};

#endif