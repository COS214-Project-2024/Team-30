#include <iostream>
#include "BuildingFactory.h"
#include "Landmark.h"
#include "LandmarkFactory.h"

Building *LandmarkFactory::createBuilding(){
    std::cout<<"New Landmark Made"<<std::endl;
    return new Landmark();
}