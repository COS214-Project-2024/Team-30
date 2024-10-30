#include <iostream>

#include "Commercial.h"
#include "CommercialFactory.h"

//constructor for Commercial
Commercial::Commercial()
{
    //initial state of Commercial Builidng should be Underconstruction
}

//builds a Commercial building, calls Commerical Factory to create building
void Commercial::build() {
    CommercialFactory* newComm = new CommercialFactory();
    newComm->createBuilding();
    //change state to built here
    std::cout<<"New Commercial Building Built"<<std::endl;

}

//clones a Commercial Building
Commercial *Commercial::clone(){
    Commercial* clonedComm = new Commercial(*this);

}