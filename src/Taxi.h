#ifndef TAXI_H
#define TAXI_H

#include "PublicTransport.h"

/**
 * @brief Taxi 
 *
 * Taxi class is the public transport that makes use of roads
 */
class Taxi : public publicTransport {
public:

    /**
     * @brief Constructs a Taxi object with a specified name and capacity
     *
     * @param capacity The maximum number of passengers the taxi can carry
     * @param from The building 
     */
    Taxi(int capacity, shared_ptr<Building> from);

    /**
     * @brief Travels to a specified building and transports passengers.
     *
     * moves through the linked list to arrive at destination
     *
     * @param to A shared pointer to the destination building where passengers
     *           will be transported.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // TAXI_H

