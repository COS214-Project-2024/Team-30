#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Buildings.h"

using namespace std;

class PowerPlant {
    public:
        PowerPlant();
        void generateElectricity(Building b);
        bool repair();

    private:
        bool working;
};

#endif 