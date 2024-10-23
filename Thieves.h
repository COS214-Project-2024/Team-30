#ifndef THIEVES_H
#define THIEVES_H
#include "Emergencies.h"

class Thieves : public Emergencies
{
public:
    void accessDamage(Building* buildingType) override;
};

#endif