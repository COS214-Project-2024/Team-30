#ifndef HOUSING_H
#define HOUSING_H

#include "CityGrowthObserver.h"

/**
 * @brief Observer class for monitoring and responding to housing-related changes.
 *
 * The `Housing` class is a concrete observer that implements the `CityGrowthObserver` 
 * interface. It updates housing-related statistics and infrastructure whenever 
 * there are changes in the population or other factors within the `Government` object.
 */
class Housing : public CityGrowthObserver {
public:
    /**
     * @brief Updates housing conditions based on the current state of the Government.
     *
     * This method adjusts housing resources and requirements according to the
     * population size and other relevant data from the `Government` object. 
     * It is triggered whenever there is a change in the city's conditions 
     * (such as population growth) that affects housing needs.
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