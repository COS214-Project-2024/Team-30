#include <iostream>
#include <memory>  // Include for smart pointers
#include <iomanip> 

#include "Building.h"
#include "BuildingState.h"
#include "Built.h"
#include "Underconstruction.h"
#include "Destroyed.h"

//Buildings default constructor
Building::Building(): capacity(0), buildingHealth(100), price(0),runningUtils(false){
    //setUtilities();
}

// Sets state of building to underconstruction
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

// Sets the state of the building acc to the building health
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
    std::cout << "==========================================" << std::endl;
    std::cout << std::setw(20) << std::left << "Building Type:" ;
              //<< std::setw(20) << getType() << std::endl;
    std::cout << std::setw(20) << std::left << "Building State:" 
              << std::setw(20) << currState->getStatus() << std::endl;
    std::cout << std::setw(20) << std::left << "Capacity:" 
              << std::setw(20) << capacity << std::endl;
    std::cout << std::setw(20) << std::left << "Price:" 
              << std::setw(20) << price << std::endl;
    std::cout << std::setw(20) << std::left << "Utilities Running:" 
              << std::boolalpha << runningUtils << std::endl; // Output true/false as words
    std::cout << "==========================================" << std::endl;
}

BuildingState* Building::getState()
{
    return currState.get(); // Return raw pointer to BuildingState
}

void Building::update()
{
}

Building::~Building() 
{

}

// Building::Building(BuildingState *initialState) : currState(nullptr){
//     this->currState->setState();
// }

// void showInfo() const {
//     std::cout << "Building: " << name << std::endl;
// }

// void Building::setUtilities(){
//     water = 100;
//     power = 100;
//     sewerage = 100;
//     waste = 100;
// }

// void Building::requestUtilities(){
//     std::unique_ptr<Utilities> utilities;
//     utilities->provideUtilites();
// }