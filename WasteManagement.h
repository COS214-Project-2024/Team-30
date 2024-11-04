#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Building.h"

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
     * @param b Boolean indicating if the waste management system is working.
     */
    void setWorking(bool b);
    bool getWorking();

    /**
     * @brief Removes waste from a specified building.
     * @param b The building from which waste is removed.
     * @return True if waste removal was successful, false otherwise.
     */
    int removeWaste(Building* b);

    /**
     * @brief Recycles waste for a specified building.
     * @param b The building for which waste is recycled.
     * @return True if recycling was successful, false otherwise.
     */
    void recycle();

    /**
     * @brief Repairs the waste management system, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding utility services.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the waste management system is operational. */
};

#endif // WASTEMANAGEMENT_H
