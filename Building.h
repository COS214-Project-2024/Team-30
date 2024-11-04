#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory> // Include for smart pointers
#include <algorithm>
#include "BuildingState.h"
#include "Emergencies.h"
#include "Citizen.h"

class Emergencies;

using namespace std;

class Building
{
protected:
    int id;
    unique_ptr<BuildingState> currState; 
    int capacity;
    int buildingHealth;
    int price; 
    bool runningUtils;
    vector<shared_ptr<Citizen>> residents;
    static int nextID;

     //std::string name;
     //Utilities
    // int water;
    // int power;
    // int waste;
    // int sewage;

public:
    Building(); //Building constructor
    virtual ~Building();
    int getCapacity();
    virtual void build() = 0;
    BuildingState *getState();
    void setState(unique_ptr<BuildingState> state); 
    void setCapacity(int capacity);
    void processState(); 
    virtual string getType() = 0;
    void displayInfo(); 

    void simulateEmergency(Emergencies &emergency);
    bool hasOccupant(int citizenID) const;
    void printResidents();
    bool containsCitizen(shared_ptr<Citizen> citizen);
    
    string getName();
    int getID();

    void takeDamage(int damage);
    void update();

    void recieveUtilities(); 

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void notifyCitizensOfEmergency(int damage);

    virtual unique_ptr<Building> clone() = 0; 
};

#endif
