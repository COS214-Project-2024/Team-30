#include <iostream>
#include <memory>  // Include for smart pointers

#include "Building.h"
#include "BuildingState.h"
#include "Built.h"
#include "Underconstruction.h"
#include "Destroyed.h"

// Building::Building(BuildingState *initialState) : currState(nullptr){
//     this->currState->setState();
// }

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
    cout << "Building State:\t" << currState->getStatus() << endl;
    cout << "Building Capacity:\t" << capacity << endl;
    cout << "Building price:\t" << price << endl;
    cout << "Utensils Set:\t" << runningUtils << endl;
}

BuildingState* Building::getState()
{
    return currState.get(); // Return raw pointer to BuildingState
}

// void Building::add(BuildingComponent *component)
// {
// }

// void Building::remove(BuildingComponent *component)
// {
// }

void Building::update()
{
}

void Building::recieveUtilities()
{
}

Building::~Building() 
{
   // No need for explicit delete; unique_ptr will automatically clean up
}
