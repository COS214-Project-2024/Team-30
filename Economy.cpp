#include "Economy.h"
#include <iostream>

void Economy::update(Government* g)
{
    std::cout << "Economy is growing to support population: " << g->getPopulationNum() << std::endl;
    g->calculateEmploymentRate();
    std::cout<<"\nRevised information on city"<<std::endl;
    g->printInfo();
}