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
    shared_ptr<Road> node = to->getRoad();
    if (node->containsBuilding(to))
        {
            from = to;
            this->removeAllPeople();
            cout << "The passengers have been dropped off at the destination by the Taxi!\n";
        }
    while(node->getNext() != to->getRoad())
    {
        if (node->containsBuilding(to))
        {
            from = to;
            this->removeAllPeople();
            cout << "The passengers have been dropped off at the destination by the Taxi!\n";
        }
        else
        {
            cout << "Taxi is moving off of road " << node->getID() << endl;
            node->setNext(node->getNext());
        }
    }
}

