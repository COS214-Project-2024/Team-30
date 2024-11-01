#ifndef EMERGENCIES_H
#define EMERGENCIES_H

#include "Building.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Emergencies
{
protected:
    int damageInflicted;
    unique_ptr<Building> buildingType; // Use smart pointer for buildingType

public:
    virtual void accessDamage(unique_ptr<Building> buildingType) = 0; // Updated parameter to use unique_ptr
    // Emergencies();
    virtual ~Emergencies(); // Ensure virtual destructor for proper cleanup
};

#endif
