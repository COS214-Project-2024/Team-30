#include <iostream>

#include "Landmark.h"
#include "LandmarkFactory.h"

//constructor for Landmark
Landmark::Landmark()
{
    //state of landmark building should be underconstruction
    //sorted out by buildings constructor ??
}

//builds an landmark, calls landmark factory to create landmark
void Landmark::build(){
    LandmarkFactory* newLandmark = new LandmarkFactory();
    newLandmark->createBuilding();
    //change landmark state to built here
    std::cout<<"New Landmark Built"<<std::endl;
}

//clones Landmark 
Landmark *Landmark::clone(){
    Landmark* clonedLandmark = new Landmark(*this);
}