#include "Emergencies.h"
#include "EmergencyServices.h"

int Emergencies::getDamage()
{
    return damage;
}

void Emergencies::setDamage(int newDamage)
{
    damage = newDamage;
}

Emergencies::~Emergencies() {}
