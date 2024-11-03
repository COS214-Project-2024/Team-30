#ifndef CONSTRUCTION_RESOURCE_FACTORY_H
#define CONSTRUCTION_RESOURCE_FACTORY_H

using namespace std;
#include "Resource.h"
#include "ResourceFactory.h"
#include "Wood.h"
#include "Water.h"
#include "Steel.h"
#include "Concrete.h"
#include "Coal.h"
#include <memory>
#include <string>



class ConstructionResourceFactory : public ResourceFactory
{
    public: 
        unique_ptr<Resource> createResource(const std::string& type, int capacity) override;           
};

#endif