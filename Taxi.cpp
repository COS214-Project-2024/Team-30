#include "Taxi.h"

Taxi::Taxi(int capacity, shared_ptr<Building> from)
        : publicTransport(capacity, from) {}

/**
 * @brief Travels to a specified building and transports passengers.
 *
 * Implements the leaf of the composite Transport
 *
 * @param to the new building to travel to
 */
void Taxi::Travel(shared_ptr<Building> to) {
    shared_ptr<Road> node = from->getRoad();
    if (node->containsBuilding(to))
    {
        from = to;
        this->removeAllPeople();
        cout << "The Taxi passengers have been dropped off at the destination, it was on the same road!\n";
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

