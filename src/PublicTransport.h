#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

#include "Transport.h"

using namespace std;

/**
 * @brief Represents a public transport vehicle.
 *
 * This class inherits from the Transport class and provides
 * functionality specific to public transportation methods.
 */
class publicTransport : public Transport {
public:
    /**
     * @brief Constructs a publicTransport object with a specified name, capacity, and starting building.
     *
     * @param name The name of the public transport.
     * @param capacity The maximum number of passengers the public transport can carry.
     * @param from A shared pointer to the Building where the transport is initially located.
     */
    publicTransport(int capacity, shared_ptr<Building> from);

    /**
     * @brief Travels to a specified building and transports passengers.
     *
     * This method overrides the Travel method from the Transport class and
     * defines the behavior of public transport when traveling to a destination.
     *
     * @param to A shared pointer to the Building where the public transport will travel.
     */
    virtual void Travel(shared_ptr<Building> to) override;
};

#endif // PUBLICTRANSPORT_H
