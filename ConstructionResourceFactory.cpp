#include "ConstructionResourceFactory.h"

unique_ptr<Resource> ConstructionResourceFactory::createResource(const string& type, int capacity)
{
    if (type == "wood") 
    {
        return unique_ptr<Resource>(new Wood(capacity));
    } 
    else if (type == "steel") 
    {
        return unique_ptr<Resource>(new Steel(capacity));
    } 
    else if (type == "concrete") 
    {
        return unique_ptr<Resource>(new Concrete(capacity));
    } 
    else if (type == "water") 
    {
        return unique_ptr<Resource>(new Water(capacity));
    }
    else if (type == "coal")
    {
        return unique_ptr<Resource>(new Coal(capacity));
    }
}
