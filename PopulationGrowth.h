#ifndef POPULATIONGROWTH_H
#define POPULATIONGROWTH_H

#include "CityGrowthObserver.h"

/**
 * @class PopulationGrowth
 * @brief A class that observes and responds to changes in the population of a government.
 *
 * This class implements the CityGrowthObserver interface and provides functionality
 * to update and print information related to population growth.
 */
class PopulationGrowth : public CityGrowthObserver {
public:
    /**
     * @brief Updates the observer with the current population data.
     *
     * This method is called to notify the observer of changes in the government object.
     * It should handle any updates necessary to reflect the new population.
     *
     * @param g A pointer to a Government object containing the updated population information.
     */
    void update(Government* g) override;

    /**
     * @brief Prints information about the government's population.
     *
     * This method retrieves the current population of the specified government and
     * displays relevant information about its growth and other metrics.
     *
     * @param g A pointer to a Government object whose information is to be printed.
     */
    void printInfo(Government* g);

private:
    int oldPop = 0; ///< Stores the old population number for comparison.
    double bR;      ///< Represents the birth rate.
};

#endif



// #ifndef POPULATIONGROWTH_H
// #define POPULATIONGROWTH_H

// #include "CityGrowthObserver.h"

// class PopulationGrowth : public CityGrowthObserver {
// public:
//     void update(Government* g) override;
//     void printInfo(Government* g);
// private:
//     int oldPop=0; 
//     double bR;
// };

// #endif