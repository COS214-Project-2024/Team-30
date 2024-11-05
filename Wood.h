#ifndef WOOD_H
#define WOOD_H

#include "Resource.h"

using namespace std;
#include <iostream>
#include <memory>

/**
 * @class Wood
 * @brief Represents a wood resource with a limited capacity.
 * 
 * The Wood class extends the Resource class, providing functionality for
 * managing a wood resource with refill and usage capabilities.
 */
class Wood : public Resource
{
    private: 
         int capacity; ///< Capacity of the wood resource (commented out, as it's not in use).

    public: 
        /**
         * @brief Constructs a Wood object with a specified capacity.
         * @param capacity Initial capacity of the wood resource.
         */
        Wood(int capacity);

        /**
         * @brief Gets the current capacity of the wood resource.
         * @return The current capacity as an integer.
         */
        int getCapacity() const override;

        /**
         * @brief Refills the wood resource by a specified amount.
         * @param amount Amount of wood to add to the resource.
         */
        void refill(int amount) override;

        /**
         * @brief Uses a specified amount of wood from the resource.
         * @param amount Amount of wood to use from the resource.
         * @return The actual amount of wood used.
         */
        int use(int amount) override;

};

#endif
