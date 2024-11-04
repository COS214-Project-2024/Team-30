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

class Emergencies;

using namespace std;
//
class Building
//  : public BuildingComponent
{
protected:
    // vector<Utilities*> utilities;
    unique_ptr<BuildingState> currState; // Use unique_ptr for ownership
    int capacity;
    int buildingHealth;
    int price; //? whats price : price is gonna work with city budget in government
    bool runningUtils;
    vector<shared_ptr<Citizen>> residents;

public:
    // Building(); //Building constructor
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
    string getName();

    // void add(std::unique_ptr<BuildingComponent> component) override;
    // void remove(std::unique_ptr<BuildingComponent> component) override;
    void takeDamage(int damage);
    void update();
    void recieveUtilities(); // Utilities
    // Utilities* setUtilities();

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void notifyCitizensOfEmergency(int damage);

    virtual unique_ptr<Building> clone() = 0; // Return unique_ptr
};

#endif
