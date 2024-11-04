#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "Building.h"

using namespace std;

/**
 * @class SewageSystem
 * @brief Manages sewage disposal and treatment for buildings.
 */
class SewageSystem {
public:
    /**
     * @brief Constructs a SewageSystem instance.
     */
    SewageSystem();

    /**
     * @brief Sets the operational status of the sewage system.
     * @param b Boolean indicating if the sewage system is working.
     */
    void setWorking(bool b);
    bool getWorking();

    /**
     * @brief Manages sewage disposal for a specified building.
     * @param b The building for which sewage disposal is managed.
     * @return True if disposal was successfully managed, false otherwise.
     */
    bool manageDisposal(Building* b);

    /**
     * @brief Manages sewage treatment for a specified building.
     * @param b The building for which sewage treatment is managed.
     * @return True if treatment was successfully managed, false otherwise.
     */
    void manageTreatment();

    /**
     * @brief Repairs the sewage system, returning it to working condition.
     * @return True if the repair was successful, false otherwise.
     */
    bool repair();

    /**
     * @brief Sends a notification message to citizens regarding utility services.
     * @param message The message to notify citizens.
     */
    void notifyCitizens(const string& message);

private:
    bool working; /**< Indicates if the sewage system is operational. */
};

#endif // SEWAGESYSTEM_H
