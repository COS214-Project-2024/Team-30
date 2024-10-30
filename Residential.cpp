#include <iostream>

#include "Residential.h"
#include "ResidentailFactory.h"

//creates a Residential object
Residential::Residential()
{
    //state of residnetial building should be underconstruction     !!!!!!!!!!
}

//builds a residential building, calls residential factory to create building
void Residential::build() {
    
    ResidentialFactory* newRes = new ResidentialFactory();
    newRes->createBuilding();
    //change building state to built here                           !!!!!!!!!!
    std::cout<<"New Residential Building Built"<<std::endl;
    
}

//clones Residential building
Residential *Residential::clone(){
    Residential* clonedRes = new Residential(*this);
}