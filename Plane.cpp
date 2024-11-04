#include "Plane.h"

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * This method overrides the Travel method in the PublicTransport class.
 * It moves all passengers from the plane to the specified building and
 * updates the 'from' location of the plane. After transporting the
 * citizens, the passenger list is cleared.
 *
 * @param to A shared pointer to the Building where the plane will travel.
 */
void Plane::Travel(shared_ptr<Building> to) {
    if (to) {
        for (const auto& cit : passengers) {
            to->addCitizen(cit);  // Add each passenger to the destination building.
            cout << name << " transported citizen with ID " << cit->getID()
                 << " to building: " << to->getName() << endl;
        }
        passengers.clear();  // Clear all passengers after they have been moved.
        from = to;           // Update the 'from' building to the new location.
    } else {
        cout << "Invalid destination building." << endl;  // Handle invalid destination.
    }
}
