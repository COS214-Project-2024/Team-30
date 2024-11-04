#ifndef COAL_H
#define COAL_H
#include "Resource.h"

/**
 * @class Coal
 * @brief Represents a coal resource with a limited capacity.
 * 
 * The Coal class extends the Resource class, providing functionality for
 * managing a coal resource with refill and usage capabilities.
 */
class Coal : public Resource
{
    private: 
        // int capacity; ///< Capacity of the coal resource (commented out, as it's not in use).

    public: 
        /**
         * @brief Constructs a Coal object with a specified capacity.
         * @param capacity Initial capacity of the coal resource.
         */
        Coal(int capacity);

        /**
         * @brief Gets the current capacity of the coal resource.
         * @return The current capacity as an integer.
         */
        int getCapacity() const override;

        /**
         * @brief Refills the coal resource by a specified amount.
         * @param amount Amount of coal to add to the resource.
         */
        void refill(int amount) override;

        /**
         * @brief Uses a specified amount of coal from the resource.
         * @param amount Amount of coal to use from the resource.
         * @return The actual amount of coal used.
         */
        int use(int amount) override;

};

#endif
