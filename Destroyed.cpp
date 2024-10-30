#include <iostream>

#include "Destroyed.h"
#include "BuildingState.h"
#include "Underconstruction.h"

void Destroyed::handle(){
    std::cout<<"Building has been destroyed."<<std::endl;
}

void Destroyed::changeState(){
    BuildingState* state_ = new Underconstruction();
    state_->handle();
}