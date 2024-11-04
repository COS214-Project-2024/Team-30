#include "PublicTransport.h"
#include <iostream>

publicTransport::publicTransport(std::string name, int capacity, shared_ptr<Building> from)
        : Transport(name, capacity, from) {}

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * This method overrides the Travel method from the Transport class,
 * allowing public transport to move to a new destination building and
 * transfer all passengers to that building.
 *
 * @param to A shared pointer to the Building where the public transport will travel.
 */
void publicTransport::Travel(shared_ptr<Building> to) {
    if (to) {
        cout << "Traveling to " << to->getName() << " by public transport.\n";
        for (const auto& cit : passengers) {
            to->addCitizen(cit);
            cout << "Passenger with ID " << cit->getID() << " has been transported to " << to->getName() << ".\n";
        }
        passengers.clear();  // Clear the list of passengers after transporting them.
        from = to;           // Update the 'from' building to the new location.
    } else {
        cout << "Invalid destination building.\n";
    }
}
