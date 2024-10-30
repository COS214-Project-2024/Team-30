#include <iostream>

#include "Built.h"
#include "Destroyed.h"
#include "BuildingState.h"

void Built::handle(){
    std::cout<<"Building has been built"<<std::endl;
}

void Built::changeState(){
    BuildingState* state = new Destroyed();
    state->handle();

}