#ifndef RESOURCE_FACTORY_H
#define RESOURCE_FACTORY_H
#include "Resource.h"

class ResourceFactory
{
    public: 
        ResourceFactory();
        virtual Resource* createWood() =0;
        virtual Resource* createSteel() =0;
        virtual Resource* createWater() =0;
        virtual Resource* createConcrete() =0;
        virtual Resource* createBudget() =0; 

};
#endif