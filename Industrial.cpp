#include <iostream>

#include "Industrial.h"
#include "IndustrialFactory.h"

//constructor for Industrial 
Industrial::Industrial(){
    //state of commercial building should be underconstruction
}

//builds an industrial building, calls industrial factory to create building
void Industrial::build(){
    IndustrialFactory* newInd = new IndustrialFactory();
    newInd->createBuilding();
    //change building state to built here
    std::cout<< "New Industrial Building Built"<<std::endl; 

}

//clones Industial building 
Industrial *Industrial::clone(){
    Industrial* clonedInd = new Industrial(*this);
}