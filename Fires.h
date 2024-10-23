#ifndef FIRES_H
#define FIRES_H
#include "Emergencies.h"

class Fires : public Emergencies
{
public:
    void accessDamage(Building* buildingType) override;
};

#endif