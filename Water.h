#ifndef WATER_H
#define WATER_H
#include "Resource.h"

/**
 * @class Water
 * @brief Represents a water resource with a limited capacity.
 * 
 * The Water class extends the Resource class, providing functionality for
 * managing a water resource with refill and usage capabilities.
 */
class Water : public Resource
{
    private:
        // int capacity; ///< Capacity of the water resource (commented out, as it's not in use).

    public: 
        /**
         * @brief Constructs a Water object with a specified capacity.
         * @param capacity Initial capacity of the water resource.
         */
        Water(int capacity);

        /**
         * @brief Gets the current capacity of the water resource.
         * @return The current capacity as an integer.
         */
        int getCapacity() const override;

        /**
         * @brief Refills the water resource by a specified amount.
         * @param amount Amount of water to add to the resource.
         */
        void refill(int amount) override;

        /**
         * @brief Uses a specified amount of water from the resource.
         * @param amount Amount of water to use from the resource.
         * @return The actual amount of water used.
         */
        int use(int amount) override;
};

#endif
