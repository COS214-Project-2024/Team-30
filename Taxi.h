#ifndef TAXI_H
#define TAXI_H

#include "PublicTransport.h"

/**
 * @brief Represents a taxi that can transport citizens between buildings.
 *
 * The Taxi class inherits from the Transport class and provides functionality
 * for traveling to a specified building while managing a list of passengers.
 */
class Taxi : public publicTransport {
public:

    /**
     * @brief Constructs a Taxi object with a specified name and capacity.
     *
     * @param capacity The maximum number of passengers the taxi can carry.
     * @param from The building 
     */
    Taxi(int capacity, shared_ptr<Building> from);

    /**
     * @brief Travels to a specified building and transports passengers.
     *
     * This method overrides the Travel function from the Transport class.
     * It moves all passengers from the taxi to the specified building,
     * updating the taxi's current location and clearing the list of
     * passengers after transporting them.
     *
     * @param to A shared pointer to the destination building where passengers
     *           will be transported.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // TAXI_H

