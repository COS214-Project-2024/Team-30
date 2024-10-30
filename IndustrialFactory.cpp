#include <iostream>
#include "BuildingFactory.h"
#include "IndustrialFactory.h"
#include "Industrial.h"

Building *IndustrialFactory::createBuilding(){
    std::cout<<"New Industrail Building Built."<<std::endl;
    return new Industrial();
}