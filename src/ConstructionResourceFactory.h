#ifndef CONSTRUCTION_RESOURCE_FACTORY_H
#define CONSTRUCTION_RESOURCE_FACTORY_H

#include "Resource.h"

class ConstructionResourceFactory
{
    private: 

    public: 
        Resource* createWood();
        Resource* createSteel();
        Resource* createWater();
        Resource* createConcrete();
        Resource* createBudget();        
};

#endif