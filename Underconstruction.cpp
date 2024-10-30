#include <iostream>

#include "Underconstruction.h"
#include "Built.h"
#include "BuildingState.h"

void Underconstruction::handle(){
    std::cout<<"Building is underconstruction"<<std::endl;
}

void Underconstruction::changeState(){
    BuildingState* state_ = new Built();
    state_->handle();

}