#ifndef PRIVATETRANSPORT_H
#define PRIVATETRANSPORT_H

#include "Transport.h"

using namespace std;

/**
 * @class privateTransport
 * @brief Represents a private mode of transport that inherits from the Transport class.
 *
 * The privateTransport class is a specific type of transport that allows for
 * travel between buildings. It inherits from the Transport class and implements
 * travel capabilities for private transport options.
 */
class privateTransport : public Transport {
public:
    /**
     * @brief Constructs a privateTransport with a specified name, capacity, and starting building.
     * @param name The name of the private transport.
     * @param capacity The maximum number of passengers the private transport can carry.
     * @param from A shared pointer to the Building where the transport is initially located.
     */
    privateTransport(string name, int capacity, shared_ptr<Building> from);

    /**
     * @brief Travels to a specified building and transports passengers.
     *
     * This method overrides the Travel method in the Transport class
     * and implements the specific travel logic for private transport.
     * @param to A shared pointer to the Building where the private transport will travel.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // PRIVATETRANSPORT_H


