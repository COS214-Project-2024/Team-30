#include "PrivateTransport.h"

/**
 * @brief Constructs a privateTransport object with a specified name, capacity, and starting building.
 *
 * @param name The name of the private transport.
 * @param capacity The maximum number of passengers the private transport can carry.
 * @param from A shared pointer to the Building where the transport is initially located.
 */
privateTransport::privateTransport(string name, int capacity, shared_ptr<Building> from)
        : Transport(name, capacity, from) {}

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * This method overrides the Travel method from the Transport class. It moves
 * all passengers from the private transport to the specified building and
 * updates the current location of the transport.
 *
 * @param to A shared pointer to the Building where the private transport will travel.
 */
void privateTransport::Travel(shared_ptr<Building> to) {
    /*if (to) {
        for (const auto& cit : passengers) {
            to->addCitizen(move(cit));  // Move the citizen to the destination building.
            cout << this->name << " has moved by private transport citizen with ID " << cit->getID() << endl;
        }
        from = to;  // Update the 'from' building to the new location.
    } else {
        cout << "Invalid destination building." << endl;  // Handle invalid destination.
    }*/
    shared_ptr<Building> node = to;

}
