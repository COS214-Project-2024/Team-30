
#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <unordered_map>
#include <vector>

/**
 * @class Resource
 * @brief An abstract base class representing a general resource with a limited capacity.
 * 
 * The Resource class provides a common interface for various types of resources
 * such as Steel, Water, Coal, Concrete, and Wood. Derived classes must implement
 * methods for getting capacity, using, and refilling the resource.
 */
class Resource
{
    protected:
        int capacity; ///< Capacity of the resource.

    public: 
        /**
         * @brief Virtual destructor for the Resource class.
         */
        virtual ~Resource() = default;

        /**
         * @brief Gets the current capacity of the resource.
         * @return The current capacity as an integer.
         */
         virtual int getCapacity() const = 0; // Pure virtual function


        /**
         * @brief Uses a specified amount of the resource.
         * @param amount Amount of the resource to use.
         * @return The actual amount used.
         */
        virtual int use(int amount) = 0;     // Pure virtual function
        

        /**
         * @brief Refills the resource by a specified amount.
         * @param amount Amount to add to the resource's capacity.
         */
         virtual void refill(int amount) = 0; // Pure virtual function
        
};      

#endif

