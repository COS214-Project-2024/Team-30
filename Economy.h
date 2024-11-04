#ifndef ECONOMY_H
#define ECONOMY_H

#include "CityGrowthObserver.h"

/**
 * @class Economy
 * @brief Concrete observer class that monitors and updates the economic state of the city.
 *
 * The `Economy` class inherits from `CityGrowthObserver` and implements the `update` method
 * to respond to changes in the city’s economy. This observer may adjust various economic
 * indicators within the `Government` object to reflect current economic conditions.
 */
class Economy : public CityGrowthObserver {
public:
    /**
     * @brief Updates the economic state based on the current status of the Government.
     *
     * This method is called when the `Government` notifies its observers of changes.
     * The `Economy` observer will assess the economic factors in `Government` and
     * adjust accordingly.
     *
     * @param g Pointer to the `Government` object.
     */
    void update(Government* g) override;
};

#endif




// #ifndef ECONOMY_H
// #define ECONOMY_H

// #include "CityGrowthObserver.h"

// class Economy : public CityGrowthObserver {
// public:
//     void update(Government* g) override;
// };

// #endif