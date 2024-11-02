#include "Population.h"

/**
 * @brief Retrieves the current population size.
 * 
 * @return The current population as an integer.
 */
int Population::getPopulation()
{
    return this->population;
}

/**
 * @brief Sets the population size.
 * 
 * Updates the population to a new value.
 *
 * @param a The new population size to set.
 */
void Population::setPopulation(int a)
{
    this->population = a;
}


// #include "Population.h"

// int Population::getPopulation()
// {
//     return this->population;
// }

// void Population::setPopulation(int a)
// {
//     this->population=a;
// }
