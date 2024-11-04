#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"
#include "Coal.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;

/**
 * @class PowerPlant
 * @brief Represents a power plant responsible for generating electricity and monitoring coal resources.
 */
class PowerPlant {
public:
    /**
     * @brief Constructs a PowerPlant instance with a specified coal resource.
     * @param c Shared pointer to a Coal instance used as the power plant's fuel source.
     */
    PowerPlant(shared_ptr<Coal> c);

    /**
     * @brief Sets the operational status of the power plant.
     * @param b Boolean indicating whether the power plant is operational.
     */
    void setWorking(bool b);

    /**
     * @brief Checks if the power plant is operational.
     * @return True if the power plant is operational, false otherwise.
     */
    bool getWorking();

    /**
     * @brief Sets the coal supply level for the power plant.
     * @param w The amount of coal available for distribution.
     */
    void setCoal(int w);

    /**
     * @brief Retrieves the current coal level in the power plant.
     * @return The amount of coal currently available for power generation.
     */
    int getCoal();

    /**
     * @brief Generates electricity for a specified building.
     * @param b Shared pointer to the Building receiving electricity.
     * @return The amount of electricity generated, or 0 if generation fails.
     */
    int generateElectricity(shared_ptr<Building> b);

    /**
     * @brief Repairs the power plant, making it operational again.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding the power plant's status.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the power plant is operational. */
    int coalToDistribute; /**< Amount of coal available for generating electricity. */
    shared_ptr<Coal> coalResource; /**< Shared pointer to the Coal resource used for power generation. */
};

#endif // POWERPLANT_H
