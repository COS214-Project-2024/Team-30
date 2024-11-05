#include "Plane.h"

Plane::Plane(int capacity, shared_ptr<Building> from)
        : publicTransport(capacity, from) {}
/**
 * @brief Travels to a specified building and transports passengers
 *
 * Implements the leaf of the composite Transport
 *
 * @param to the new building to travel to
 */
void Plane::Travel(shared_ptr<Building> to) {
    if (to) {
        from = to;
        this->removeAllPeople();
        cout << "The plane has landed and the passangers have been dropped off at building:\n"
            << from->getID() << endl;
    } else {
        cout << "Invalid destination building." << endl;  // Handle invalid destination.
    }
}
