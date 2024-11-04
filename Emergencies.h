#ifndef EMERGENCIES_H
#define EMERGENCIES_H

#include "Building.h"
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib> 
#include <ctime> 
using namespace std;

class Emergencies
{
protected:
    int damage;

public:
    virtual void accessDamage(shared_ptr<Building> buildingType) = 0; // Updated parameter to use unique_ptr
    virtual string getTypeOfEmergency() = 0;
    // Emergencies();
    int getDamage();
    void setDamage(int damage);
    virtual ~Emergencies(); // Ensure virtual destructor for proper cleanup
};

#endif
