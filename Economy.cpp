#include "Economy.h"
#include <iostream>

/**
 * @brief Updates the economic state based on the Government's current population and employment data.
 *
 * This implementation displays a message indicating that the economy is adapting to support the 
 * current population. It then calls `calculateEmploymentRate` on the `Government` object to 
 * adjust the employment rate, reflecting the current state of the economy. Finally, it outputs 
 * revised city information.
 *
 * @param g Pointer to the `Government` object that provides the current economic and population data.
 */
void Economy::update(Government* g)
{
    std::cout << "\n=================================================================" << std::endl;
    std::cout << "                      Economic State                                    " << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << "Economy has grown to support population: " << g->getPopulationNum() << std::endl;
     std::cout << "=================================================================" << std::endl;
    g->calculateEmploymentRate();
     std::cout << "\n=================================================================" << std::endl;
    std::cout << "\nRevised information on city" << std::endl;
    g->printInfo();
}

// #include "Economy.h"
// #include <iostream>

// void Economy::update(Government* g)
// {
//     std::cout << "Economy is growing to support population: " << g->getPopulationNum() << std::endl;
//     g->calculateEmploymentRate();
//     std::cout<<"\nRevised information on city"<<std::endl;
//     g->printInfo();
// }