#ifndef CONCRETE_H
#define CONCRETE_H
#include "Resource.h"

/**
 * @class Concrete
 * @brief Represents a concrete resource with a limited capacity.
 * 
 * The Concrete class extends the Resource class, providing functionality for
 * managing a concrete resource with refill and usage capabilities.
 */
class Concrete : public Resource
{
    private: 
         int capacity; ///< Capacity of the concrete resource (commented out, as it's not in use).

    public: 
        /**
         * @brief Constructs a Concrete object with a specified capacity.
         * @param capacity Initial capacity of the concrete resource.
         */
        Concrete(int capacity);

        /**
         * @brief Gets the current capacity of the concrete resource.
         * @return The current capacity as an integer.
         */
        int getCapacity() const override;

        /**
         * @brief Refills the concrete resource by a specified amount.
         * @param amount Amount of concrete to add to the resource.
         */
        void refill(int amount) override;

        /**
         * @brief Uses a specified amount of concrete from the resource.
         * @param amount Amount of concrete to use from the resource.
         * @return The actual amount of concrete used.
         */
        int use(int amount) override;

};

#endif
