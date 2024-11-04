#ifndef CITYGROWTHOBSERVER_H
#define CITYGROWTHOBSERVER_H

#include "Government.h"
class Government;

/**
 * @class CityGrowthObserver
 * @brief Abstract base class for observers that monitor and respond to city growth changes.
 *
 * This class provides an interface for observing changes in the city's growth metrics. 
 * Derived classes implement the `update` function to define their response 
 * to changes in the `Government` class.
 */
class CityGrowthObserver {
public:
    /**
     * @brief Updates the observer with the latest changes from the Government.
     *
     * This function is called by the `Government` class to notify the observer of any
     * relevant changes in city growth factors. Derived classes should implement this 
     * function to specify how they respond to such updates.
     * 
     * @param g Pointer to the `Government` object that notifies the observer of changes.
     */
    virtual void update(Government* g) = 0;

    /**
     * @brief Virtual destructor.
     *
     * Clean up of derived classes.
     */
    virtual ~CityGrowthObserver() = default;
};

#endif



// #ifndef CITYGROWTHOBSERVER_H
// #define CITYGROWTHOBSERVER_H

// #include "Government.h"
// class Government;

// class CityGrowthObserver{
//     public:
//         virtual void update(Government* g) = 0;
//         virtual ~CityGrowthObserver() = default;
// };

// #endif