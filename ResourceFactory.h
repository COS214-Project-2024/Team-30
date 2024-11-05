#ifndef RESOURCE_FACTORY_H
#define RESOURCE_FACTORY_H
#include "Resource.h"
using namespace std;
#include <string>
#include <memory>

/**
 * @class ResourceFactory
 * @brief An abstract factory class for creating different types of resources.
 * 
 * The ResourceFactory class provides an interface for creating resources such as
 * Water, Wood, Steel, Coal, and Concrete. Derived factory classes should implement
 * the `createResource` method to instantiate specific resource types based on
 * the provided type and capacity.
 */
class ResourceFactory
{
    public: 
        /**
         * @brief Constructs a ResourceFactory object.
         */
        ResourceFactory();

        /**
         * @brief Virtual destructor for the ResourceFactory class.
         */
        virtual ~ResourceFactory() = default; 

        /**
         * @brief Creates a resource of a specified type with a given capacity.
         * @param type The type of resource to create (e.g., "Water", "Wood").
         * @param capacity The initial capacity of the created resource.
         * @return A unique pointer to the created Resource object.
         */
        virtual std::unique_ptr<Resource> createResource(const std::string& type, int capacity) = 0;
};

#endif
