#include "Infrastructure.h"
#include <iostream>

void Infrastructure::update(Government* g)
{
     std::cout << "\n=================================================================" << std::endl;
     std::cout << "                      Infrastructure" << std::endl;
     std::cout << "=================================================================" << std::endl;

     std::cout << "Infrastructure is expanding, due to the increased populations. " << std::endl;

     std::cout << "=================================================================" << std::endl;
     g->increaseInfurstructure();
     // g->getInfrastructure();
     // std::cout << g->getInfrastructure();
}