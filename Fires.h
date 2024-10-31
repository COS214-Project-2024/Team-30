#ifndef FIRES_H
#define FIRES_H
#include "Emergencies.h"

class Fires : public Emergencies
{
public:
    void accessDamage(unique_ptr<Building> buildingType) override;
};

#endif