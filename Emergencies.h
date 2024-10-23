#ifndef EMERGENCIES_H
#define EMERGENCIES_H

#include "Building.h"

class Emergencies
{
protected:
    int damageInflicted;
    Building* buildingType;
public:
    virtual void accessDamage(Building* buildingType) = 0;
    Emergencies();
    ~Emergencies();
};



#endif