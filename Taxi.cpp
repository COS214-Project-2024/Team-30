#include "Taxi.h"

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * This method moves all passengers from the taxi to the specified
 * building. It iterates over the list of passengers, adds each one
 * to the destination building, and prints out a message for each
 * transported citizen. After transporting, the taxi's list of
 * passengers is cleared, and the current location is updated to
 * the destination building.
 *
 * @param to A shared pointer to the destination building where passengers
 *           will be transported. If the pointer is null, an error message
 *           will be displayed.
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
