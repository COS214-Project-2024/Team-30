#ifndef PLANE_H
#define PLANE_H

#include "PublicTransport.h"

using namespace std;

/**
 * @class Plane
 * @brief Represents a plane that inherits from the PublicTransport class.
 *
 * The Plane class is a specific type of public transport that allows for
 * air travel. It inherits from the PublicTransport class and implements
 * travel capabilities.
 */
class Plane : public publicTransport {
public:
    Plane() : publicTransport(0,nullptr) {}
    /**
     * @brief Constructs a Plane with a specified name and capacity.
     * @param name The name of the plane.
     * @param capacity The maximum number of passengers the plane can carry.
     */
    Plane(int capacity, shared_ptr<Building> from);

    /**
     * @brief Travels to a specified building.
     *
     * This method overrides the Travel method in the PublicTransport class
     * and implements the specific travel logic for the plane.
     * @param to A shared pointer to the Building where the plane will travel.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // PLANE_H

