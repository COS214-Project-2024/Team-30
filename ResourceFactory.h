#ifndef RESOURCE_FACTORY_H
#define RESOURCE_FACTORY_H
#include "Resource.h"
using namespace std;
#include <string>
#include <memory>

class ResourceFactory
{
    public: 
        ResourceFactory();
        virtual ~ResourceFactory() = default; 
        virtual std::unique_ptr<Resource> createResource(const std::string& type, int capacity) = 0;
};
#endif