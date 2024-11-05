#include "PrivateTransport.h"

/**
 * @brief Constructs a privateTransport object with a specified name, capacity, and starting building.
 *
 * @param name The name of the private transport.
 * @param capacity The maximum number of passengers the private transport can carry.
 * @param from A shared pointer to the Building where the transport is initially located.
 */
privateTransport::privateTransport(int capacity, shared_ptr<Building> from)
        : Transport(capacity, from) {}

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
    shared_ptr<Road> node = from->getRoad();
    if (node->containsBuilding(to))
    {
        from = to;
        this->removeAllPeople();
        cout << "The passengers have been dropped off at the destination, it was on the same road!\n";
        return;
    }
    while(node->getNext() != from->getRoad())
    {
        vector<Sign> signs = node->getSigns();
        if (!signs.empty()) {
            cout << "On this road we see:\n";
            for (Sign &sign: signs) {
                cout << "A " << sign.getType() << "that says: '" <<sign.getMessage() << endl;
            }
        }
        if (node->containsBuilding(to))
        {
            from = to;
            this->removeAllPeople();
            cout << "The passengers have been dropped off at the destination!\n";
            return;
        }
        else
        {
            cout << "Moving off of road " << node->getID() << endl;
            node = node->getNext();
        }
    }

}
