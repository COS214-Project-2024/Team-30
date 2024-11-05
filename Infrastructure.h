#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "CityGrowthObserver.h"

/**
 * @class Infrastructure
 * @brief A class that observes and manages infrastructure adjustments based on city growth.
 *
 * The Infrastructure class implements the CityGrowthObserver interface to respond 
 * to changes in the population of a government entity.
 */
class Infrastructure : public CityGrowthObserver {
public:
    /**
     * @brief Updates the infrastructure in response to population changes.
     *
     * This method is called whenever there is an update in the city's
     * population.
     *
     * @param g A pointer to a Government object that provides the updated population information.
     */
    void update(Government* g) override;
};

#endif



// #ifndef INFRASTRUCTURE_H
// #define INFRASTRUCTURE_H

// #include "CityGrowthObserver.h"

// class Infrastructure : public CityGrowthObserver {
// public:
//     void update(Government* g) override;
// };

// #endif