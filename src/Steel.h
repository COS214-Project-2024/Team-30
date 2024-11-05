
#ifndef STEEL_H
#define STEEL_H
#include "Resource.h"
class Resource;

/**
 * @class Steel
 * @brief Represents a steel resource with a limited capacity.
 * 
 * The Steel class extends the Resource class, providing functionality for
 * managing a steel resource with refill and usage capabilities.
 */
class Steel : public Resource
{
    private: 
         int capacity; ///< Capacity of the steel resource (commented out, as it's not in use).

    public: 
        /**
         * @brief Constructs a Steel object with a specified capacity.
         * @param capacity Initial capacity of the steel resource.
         */
        Steel(int capacity);

        /**
         * @brief Gets the current capacity of the steel resource.
         * @return The current capacity as an integer.
         */
        int getCapacity() const override;

        /**
         * @brief Refills the steel resource by a specified amount.
         * @param amount Amount of steel to add to the resource.
         */
        void refill(int amount) override;

        /**
         * @brief Uses a specified amount of steel from the resource.
         * @param amount Amount of steel to use from the resource.
         * @return The actual amount of steel used.
         */
        int use(int amount) override;
};

#endif

