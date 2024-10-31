#ifndef THIEVES_H
#define THIEVES_H
#include "Emergencies.h"

class Thieves : public Emergencies
{
public:
    void accessDamage(unique_ptr<Building> buildingType) override;
};

#endif