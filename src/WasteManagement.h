#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Building.h"
#include "Citizen.h" // Assuming this is the class for Citizen objects

#include <string>
#include <vector>
#include <memory> // for smart pointers

using namespace std;

/**
 * @class WasteManagement
 * @brief Manages waste removal and recycling for buildings.
 */
class WasteManagement {
public:
    /**
     * @brief Constructs a WasteManagement instance.
     */
    WasteManagement();

    /**
     * @brief Sets the operational status of the waste management system.
     * @param b Boolean indicating if the waste management system is operational.
     */
    void setWorking(bool b);

    /**
     * @brief Checks if the waste management system is operational.
     * @return True if operational, false otherwise.
     */
    bool getWorking();

    /**
     * @brief Removes waste from a specified building.
     * @param b Shared pointer to the building from which waste is removed.
     * @return Amount of waste removed, or 0 if removal fails.
     */
    int removeWaste(shared_ptr<Building> b);

    /**
     * @brief Recycles waste for buildings.
     */
    void recycle();

    /**
     * @brief Repairs the waste management system, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding the waste management services.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the waste management system is operational. */
};

#endif // WASTEMANAGEMENT_H
