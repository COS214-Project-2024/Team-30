#include "Taxi.h"

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * Implements the leaf of the composite Transport
 *
 * @param to the new building to travel to
 */
void Taxi::Travel(shared_ptr<Building> to) {
    if (to) {
        for (const auto& cit : passengers) {
            to->addCitizen(cit);
            cout << name << " transported citizen with ID " << cit->getID() << " to building: " << to->getName() << endl;
        }
        passengers.clear();  // Clear all passengers after they have been moved.
        from = to;           // Update the 'from' building to the new location.
    } else {
        cout << "Invalid destination building." << endl;
    }
}
