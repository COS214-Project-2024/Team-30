#include <iostream>
#include "BuildingFactory.h"
#include "CommercialFactory.h"
#include "Commercial.h"

Building *CommercialFactory::createBuilding(){
    std::cout<<"New Commercial Building Built"<<std::endl;
    return new Commercial();
}

