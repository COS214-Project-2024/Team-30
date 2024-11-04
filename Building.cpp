#include <iostream>
#include <memory> // Include for smart pointers
#include <iomanip>
#include <algorithm>
#include "Building.h"
#include "BuildingState.h"
#include "Built.h"
#include "Underconstruction.h"
#include "Destroyed.h"


// Building::Building(BuildingState *initialState) : currState(nullptr){
//     this->currState->setState();
// }
int Building::nextID = 1; // or 0, depending on your starting point for IDs

Building::Building() : id(nextID++)
{
    water = 0;
    power = 0;
    sewerage = 0;
    waste = 0;
}

// sets state of building to underconstruction
void Building::setState(unique_ptr<BuildingState> state)
{
    // note: just an idea
    /*if (runningUtils == false && state->getStatus() == "Built")
    {
        cout << "Building still underconstruction, No utilities set"<<endl;
        return;
    }*/
    currState = std::move(state); // Move the unique_ptr
    // currState->handle();
}

// set the state of the building acc to the building health
void Building::processState()
{
    int health;
    health = buildingHealth;

    if (health < 25)
    {
        currState = make_unique<Destroyed>(); // Create a new unique_ptr
        currState->handle();
    }
    else if ((health >= 25) && (health < 80))
    {
        currState = make_unique<Underconstruction>(); // Create a new unique_ptr
        currState->handle();
    }
    else if (health >= 80)
    {
        currState = make_unique<Built>(); // Create a new unique_ptr
        currState->handle();
    }
}

void Building::displayInfo()
{
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << std::setw(20) << std::left << "Building ID:"
              << std::setw(20) << getID() << std::endl; // New line for Building ID
    std::cout << std::setw(20) << std::left << "Building Type:"
              << std::setw(20) << getType() << std::endl;
    std::cout << std::setw(20) << std::left << "Building State:"
              << std::setw(20) << currState->getStatus() << std::endl;
    std::cout << std::setw(20) << std::left << "Capacity:"
              << std::setw(20) << capacity << std::endl;
    std::cout << std::setw(20) << std::left << "Price:"
              << std::setw(20) << price << std::endl;
    std::cout << std::setw(20) << std::left << "Utilities Running:"
              << std::boolalpha << runningUtils << std::endl; // Output true/false as words
    std::cout << "------------------------------------------------------------" << std::endl;
}

BuildingState *Building::getState()
{
    return currState.get(); // Return raw pointer to BuildingState
}

// void Building::add(BuildingComponent *component)
// {
// }

// void Building::remove(BuildingComponent *component)
// {
// }

void Building::receiveUtilities(Coal* c, Water* w) {
    // Convert `this` to `shared_ptr` and pass it to Utilities
    std::shared_ptr<Building> buildingPtr = shared_from_this();
    utils = std::make_unique<Utilities>(buildingPtr, c, w);
}

void Building::takeDamage(int damage)
{
    buildingHealth -= damage;
    cout << "Building took " << damage << " damage. Health is now " << buildingHealth << endl;

    if (buildingHealth <= 0)
    {
        cout << "Building is destroyed." << endl;
        setState(make_unique<Destroyed>());
    }
}

void Building::simulateEmergency(Emergencies &emergency)
{
    emergency.accessDamage(this->clone());
}

// void Building::add(std::unique_ptr<BuildingComponent> component) {
//     std::cout << "[Warning] Operation Unsupported: Cannot add components to a leaf node." << std::endl;
// }

// void Building::remove(std::unique_ptr<BuildingComponent> component) {
//     std::cout << "[Warning] Operation Unsupported: Leaf nodes cannot remove components." << std::endl;
// }

void Building::addCitizen(shared_ptr<Citizen> citizen)
{
    if (residents.size() < capacity)
    {
        residents.push_back(citizen);
    }
    else
    {
        cout << "Building is at full capacity!" << endl;
    }
}

void Building::removeCitizen(shared_ptr<Citizen> citizen)
{
    residents.erase(remove(residents.begin(), residents.end(), citizen), residents.end());
}

void Building::notifyCitizensOfEmergency(int damage)
{
    for (auto &resident : residents)
    {
        resident->reactToEmergency(damage);
    }
}
void Building::setCapacity(int capacity)
{
    this->capacity = capacity;
}

bool Building::hasOccupant(int citizenID) const
{
    return std::any_of(residents.begin(), residents.end(), [citizenID](const shared_ptr<Citizen> &resident)
                       { return resident->getID() == citizenID; });
}

Building::~Building()
{
}

int Building::getCapacity()
{
    return capacity;
}

bool Building::containsCitizen(shared_ptr<Citizen> citizen)
{
    auto it = find(residents.begin(), residents.end(), citizen);
    if (it == residents.end())
    {

        return false;
    }
    return true;
}

void Building::printResidents()
{
    if (residents.empty())
    {
        cout << "No residents in the building." << endl;
        return;
    }
    cout << "Residents' ID numbers:\n";
    for (const auto &resident : residents)
    {
        if (resident)
        {
            cout << resident->getID() << "\n";
        }
    }
    cout << endl;
}
int Building::getID()
{
    return id;
}

void Building::setUtilities()
{
    water = 100;
    power = 100;
    sewerage = 100;
    waste = 100;
}


int Building::getWater()
{
    return water;
}

int Building::getPower()
{
    return power;
}

int Building::getSewerage()
{
    return sewerage;
}

int Building::getWaste()
{
    return waste;
}

void Building::setWater(int water)
{
    this->water = water;
}
void Building::setPower(int power)
{
    this->power = power;
}
void Building::setSewage(int sewerage)
{
    this->sewerage = sewerage;
}
void Building::setWaste(int waste)
{
    this->waste = waste;
}
void Building::receiveWater(int amount) {
    if (amount > 0) {
        water += amount;
        cout << "Building received " << amount << " units of water. Total water: " << water << endl;
    } else {
        cout << "Invalid water amount. No water received." << endl;
    }
}
void Building::receiveElectricity(int amount) {
    if (amount > 0) {
        // Assuming there's a member variable to track the building's electricity supply
        power += amount;
        std::cout << "Building received " << amount << " units of electricity. Total electricity: " << power << std::endl;
    } else {
        std::cout << "Invalid electricity amount. No electricity received." << std::endl;
    }
}
    void Building::receiveUtilities(Coal* c, Water* w) {
        std::shared_ptr<Building> buildingPtr = shared_from_this();
        utils = std::make_unique<Utilities>(buildingPtr, c, w);
        
        // Check if utilities are set and if building can transition to Built state
        checkConstructionStatus();
    }

    void Building::checkConstructionStatus() {
        if (currState && dynamic_cast<Underconstruction*>(currState.get())) {
            // Check if conditions for being built are met, e.g. utilities received
            if (power > 0 && water > 0 && waste > 0) { // Adjust conditions as needed
                setState(make_unique<Built>());
            }
        }
    }
