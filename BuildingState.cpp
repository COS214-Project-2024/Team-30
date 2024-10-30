#include <iostream>

#include "BuildingState.h"
#include "Underconstruction.h"

void BuildingState::setBuilding(Building *currbuilding){
    this->building = currbuilding;
}

void BuildingState::setState(){
    BuildingState* startState = new Underconstruction();
    startState->handle();
}