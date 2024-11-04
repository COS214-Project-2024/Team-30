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
 * @brief Represents a power plant responsible for generating electricity and observing coal resources.
 */
class PowerPlant : public ResourceObserver {
public:
    /**
     * @brief Constructs a PowerPlant instance.
     */
    PowerPlant(shared_ptr<Coal> c);

    /**
     * @brief Sets the operational status of the power plant.
     * @param b Boolean indicating if the power plant is working.
     */
    void setWorking(bool b);
    bool getWorking();

    void setCoal(int w)
    int getCoal();

    /**
     * @brief Generates electricity for a specified building.
     * @param b The building receiving electricity.
     * @return True if electricity generation was successful, false otherwise.
     */
    int generateElectricity(shared_ptr<Building> b);

    /**
     * @brief Repairs the power plant, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding utility services.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the power plant is operational. */
    int coalToDistribute;
    shared_ptr<Coal> coalResource;
    vector<shared_ptr<Citizen>> residents;
};

#endif // POWERPLANT_H
