#ifndef THIEVES_H
#define THIEVES_H
#include "Emergencies.h"

class Thieves : public Emergencies
{
public:
    void accessDamage(shared_ptr<Building> buildingType) override;
    string getTypeOfEmergency() override;
};

#endif