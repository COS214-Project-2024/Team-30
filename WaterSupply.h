#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Building.h"
#include "ResourceObserver.h"
#include "Water.h"

#include <memory>
#include <string>
#include <vector>

using namespace std;

/**
 * @class WaterSupply
 * @brief Manages water distribution for buildings and observes water resources.
 */
class WaterSupply : public ResourceObserver {
public:
    /**
     * @brief Constructs a WaterSupply instance with a given water resource.
     * @param w Shared pointer to the Water resource.
     */
    WaterSupply(shared_ptr<Water> w);

    /**
     * @brief Sets the operational status of the water supply system.
     * @param w Boolean indicating if the water supply system is operational.
     */
    void setWorking(bool w);

    /**
     * @brief Checks if the water supply system is operational.
     * @return True if operational, false otherwise.
     */
    bool getWorking();

    /**
     * @brief Sets the amount of water to distribute.
     * @param w Amount of water to add to the water distribution level.
     */
    void setWater(int w);

    /**
     * @brief Retrieves the current water distribution level.
     * @return Amount of water available for distribution.
     */
    int getWater();

    /**
     * @brief Distributes water to a specified building.
     * @param b Shared pointer to the building receiving water.
     * @return The amount of water distributed, or 0 if distribution fails.
     */
    int distributeWater(shared_ptr<Building> b);

    /**
     * @brief Repairs the water supply system, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding the status of water supply services.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the water supply system is operational. */
    int waterToDistribute; /**< Amount of water available for distribution. */
    shared_ptr<Water> waterResource; /**< Shared pointer to the water resource. */
};

#endif // WATERSUPPLY_H
