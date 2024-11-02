#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"
#include "ResourceObserver.h"
#include "Coal.h"

using namespace std;

/**
 * @class PowerPlant
 * @brief Represents a power plant responsible for generating electricity and observing coal resources.
 */
class PowerPlant : public ResourceObserver {
public:
    /**
     * @brief Constructs a PowerPlant instance.
     */
    PowerPlant();

    /**
     * @brief Sets the operational status of the power plant.
     * @param b Boolean indicating if the power plant is working.
     */
    void setWorking(bool b);

    /**
     * @brief Generates electricity for a specified building.
     * @param b The building receiving electricity.
     * @return True if electricity generation was successful, false otherwise.
     */
    bool generateElectricity(Building b);

    /**
     * @brief Repairs the power plant, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Updates the resource level of coal needed by the power plant.
     */
    void updateResourceLevel();

private:
    bool working; /**< Indicates if the power plant is operational. */
};

#endif // POWERPLANT_H
