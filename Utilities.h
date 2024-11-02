#ifndef UTILITIES_H
#define UTILITIES_H

#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"

#include "Building.h"

#include <string>

using namespace std;

class Utilities {
    public:
        Utilities(Building b);
        void notifyCitizens(const std::string& message);

    private:
        PowerPlant powerPlant;
        SewageSystem sewageSystem;
        WasteManagement wasteManagement;
        WaterSupply waterSupply;
};

#endif