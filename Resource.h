#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <unordered_map>
#include <vector>

#include "ResourceObserver.h"
#include "Steel.h"
#include "Water.h"
#include "Coal.h"
#include "Concrete.h"
#include "Wood.h"

class Resource
{
    protected:
        int capacity;

    public: 
        Resource( int capacity);
        virtual ~Resource() = default;

        virtual int getCapacity() const = 0;
        virtual void use(int amount) = 0;
        virtual void refill(int amount) = 0;

        bool isCritical() const;
};      

#endif