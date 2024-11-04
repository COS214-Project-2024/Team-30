#ifndef HOUSING_H
#define HOUSING_H

#include "CityGrowthObserver.h"

/**
 * @brief Observer class for monitoring if housing needs are met.
 *
 * The `Housing` class is a concrete observer that implements the `CityGrowthObserver` 
 * interface. 
 */
class Housing : public CityGrowthObserver {
public:
    /**
     * @brief Determines if housing needs to be increased.
     *
     * This method adjusts housing resources and requirements according to the
     * population size and other relevant data from the `Government` object. 
     * It is triggered whenever there is a change in poulation.
     *
     * @param g Pointer to the `Government` object that contains the latest city data.
     */
    void update(Government* g) override;
};

#endif


// #ifndef HOUSING_H
// #define HOUSING_H

// #include "CityGrowthObserver.h"

// class Housing : public CityGrowthObserver {
// public:
//     void update(Government* g) override;
// };

// #endif