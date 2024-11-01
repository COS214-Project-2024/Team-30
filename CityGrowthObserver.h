#ifndef CITYGROWTHOBSERVER_H
#define CITYGROWTHOBSERVER_H

#include "Government.h"
class Government;

class CityGrowthObserver{
    public:
        virtual void update(Government* g) = 0;
        virtual ~CityGrowthObserver() = default;
};

#endif