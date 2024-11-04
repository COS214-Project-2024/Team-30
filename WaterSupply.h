#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Building.h"
#include "ResourceObserver.h"
#include "Water.h"

using namespace std;

/**
 * @class WaterSupply
 * @brief Manages water distribution for buildings and observes water resources.
 */
class WaterSupply : public ResourceObserver {
public:
    /**
     * @brief Constructs a WaterSupply instance.
     */
    WaterSupply();

    /**
     * @brief Sets the operational status of the water supply system.
     * @param b Boolean indicating if the water supply system is working.
     */
    void setWorking(bool b);
    void setWater(int w)

    /**
     * @brief Distributes water to a specified building.
     * @param b The building receiving water.
     * @return True if water distribution was successful, false otherwise.
     */
    bool distributeWater(Building b);

    /**
     * @brief Repairs the water supply system, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Updates the resource level of water.
     */
    void updateResourceLevel(bool b);

private:
    bool working; /**< Indicates if the water supply system is operational. */
    int waterToDistribute;
};

#endif // WATERSUPPLY_H
