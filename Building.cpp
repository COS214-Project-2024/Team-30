#include <iostream>

#include "Building.h"
#include "BuildingState.h"
#include "Built.h"
#include "Underconstruction.h"
#include "Destroyed.h"

Building::Building(BuildingState *initialState) : currState(nullptr){
    this->currState->setState();
}

//sets state of building to underconstruction
void Building::setState(BuildingState *state){
    BuildingState* state_ = new Underconstruction();
    state_->handle();
}

//set the state of the building acc to the building health
void Building::processState(){
    int health;
    health = buildingHealth();

    if(health < 25){
        currState = new Destroyed();
        currState->handle();
    } else if((health>25) && (health<80))
    {
        currState = new Underconstruction();
        currState->handle();
    }else if(health>80){
        currState = new Built();
        currState->handle();
    }
}

int Building::buildingHealth(){
    //use utilities to determine the building health 

}

void Building::add(BuildingComponent *component){

}

void Building::remove(BuildingComponent *component){

}

void Building::update(){

}

void Building::recieveUtilities(){

}
