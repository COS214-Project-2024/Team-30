#ifndef FIRES_H
#define FIRES_H
#include "Emergencies.h"

class Fires : public Emergencies
{
public:
    void accessDamage(shared_ptr<Building> buildingType) override;
    string getTypeOfEmergency() override;
   

};

#endif