#ifndef INJUREDPERSONNAL_H
#define INJUREDPERSONNAL_H
#include "Emergencies.h"

class InjuredPersonnal : public Emergencies
{
public:
    void accessDamage(Building* buildingType) override;
};

#endif