#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <vector>
#include <memory>
#include "Citizen.h"
#include "Building.h"
#include <algorithm>

using namespace std;

class Building;

/**
 * @brief Abstract base class representing a transport vehicle.
 *
 * The Transport class manages passengers, their capacity, and the building
 * from which they travel. It provides methods for adding and removing passengers,
 * as well as for traveling to a new destination building.
 */
class Transport {
protected:
    vector<shared_ptr<Citizen>> passengers; ///< List of passengers currently in the transport.
    int capacity; ///< Maximum number of passengers the transport can carry.
    string name; ///< Name of the transport.
    shared_ptr<Building> from; ///< The building from which the transport departs.

public:
    /**
     * @brief Construct a new Transport object.
     *
     * @param name Name of the transport.
     * @param capacity Maximum capacity of the transport.
     * @param from Shared pointer to the building from which the transport starts.
     */
    Transport(int capacity, shared_ptr<Building> from);

    /**
     * @brief Default destructor for the Transport class.
     */
    virtual ~Transport() = default; // default destructor

    /**
     * @brief Adds a citizen as a passenger to the transport.
     *
     * @param c Shared pointer to the citizen to be added as a passenger.
     */
    void addPeople(shared_ptr<Citizen> c);

    /**
     * @brief Removes a specified citizen from the transport.
     *
     * @param c Shared pointer to the citizen to be removed.
     */
    void removePeople(shared_ptr<Citizen> c);

    /**
     * @brief Abstract method for traveling to a new building.
     *
     * This method must be implemented by derived classes to define
     * the specific travel behavior.
     *
     * @param to Shared pointer to the destination building.
     */
    virtual void Travel(shared_ptr<Building> to) = 0;

    /**
     * @brief Removes all passengers from the transport.
     *
     * All passengers are transferred back to the building they came from.
     */
    void removeAllPeople();

    /**
     * @brief Prints the IDs of all passengers currently in the transport.
     *
     * Displays a message if there are no passengers in the vehicle.
     */
    void printPassengers();
};

#endif // TRANSPORT_H


