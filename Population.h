#ifndef POPULATION_H
#define POPULATION_H

#include "Government.h"

/**
 * @brief Represents the population component in the city model.
 *
 * The `Population` class extends `Government` and provides methods to get and set 
 * the population size. It serves as an interface for managing population-specific 
 * data within the city's government framework.
 */
class Population : public Government {
public:
    /**
     * @brief Retrieves the current population size.
     * 
     * @return The current population as an integer.
     */
    int getPopulation();

    /**
     * @brief Sets the population size.
     * 
     * Updates the population to a new value.
     *
     * @param a The new population size to set.
     */
    void setPopulation(int a);

private:
    int population; /**< Holds the current population size */
};

#endif


// #ifndef POPULATION_H
// #define POPULATION_H

// #include "Government.h"
// class Population :public Government{
//     public:
//         int getPopulation();
//         void setPopulation(int a);
//     private: 
//         int population;
// };

// #endif