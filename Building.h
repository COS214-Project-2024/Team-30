#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory> // Include for smart pointers
#include<algorithm>
//#include "BuildingState.h"
// #include "Utilities.h"
//#include "BuildingComponent.h"
//#include "Emergencies.h"
#include "Citizen.h"

class Emergencies;
class BuildingState;

using namespace std;
//
class Building
//  : public BuildingComponent
{
protected:
    // vector<Utilities*> utilities;
    //unique_ptr<BuildingState> currState; // Use unique_ptr for ownership
    int capacity;
    vector<shared_ptr<Citizen>> residents;
    string name;
    //maybe add in a type checker for airport or train station or taxi rank

public:
    Building(int,string); //Building constructor

    void addCitizen(shared_ptr<Citizen> citizen);
    void removeCitizen(shared_ptr<Citizen> citizen);
    void printResidents();
    void notifyCitizensOfEmergency(int damage);
    string getName();
    bool containsCitizen(shared_ptr<Citizen> citizen);

    //virtual unique_ptr<Building> clone() = 0; // Return unique_ptr
};

#endif