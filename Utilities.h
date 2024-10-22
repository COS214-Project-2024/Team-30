#ifndef UTILITIES_H
#define UTILITIES_H

#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"
#include "Buildings .h"

using namespace std;
// Facade: Provide a unified interface to a set of interfaces in a subsystem. 
// Facade defines a higher-level interface that makes the subsystem easier to use.
class Utilities {
    public:
        Utilities(Building b);

    private:
        PowerPlant powerPlant;
        SewageSystem sewageSystem;
        WasteManagement wasteManagement;
        WaterSupply waterSupply;
};

#endif