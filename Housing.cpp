#include "Housing.h"
#include <iostream>

void Housing::update(Government* g)
{
    std::cout << "\n=================================================================" << std::endl;
    std::cout<<  "                 Review on Housing Needs\n";
    std::cout << "=================================================================" << std::endl;
    int ResCap =g->ResidentialCapacity();
    if(ResCap<g->getPopulationNum()){
        std::cout<<"The current capacity of Residential buildings is "<<ResCap<<" .\n";
        std::cout<<"Please consider building new Residential buildings to support the current growth in population.\n\n";
    }else{
        std::cout<<"Current Residential Capacity: "<<ResCap<<"\n";
        std::cout<<"The current Residential capacity is sufficient.\n";
    }
    std::cout << "=================================================================" << std::endl;

}
