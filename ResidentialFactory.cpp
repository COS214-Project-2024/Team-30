#include <iostream>
#include "BuildingFactory.h"
#include "ResidentailFactory.h"
#include "Residential.h"


Building *ResidentialFactory::createBuilding(){
    std::cout<<"New Residential Building is Underconstruction"<<std::endl;
    return new Residential();
    
}
