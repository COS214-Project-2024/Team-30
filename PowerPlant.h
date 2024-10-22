#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Buildings.h"
#include "ResourceObserver.h"

using namespace std;

class PowerPlant : public ResourceObserver {
    public:
        PowerPlant();
        void generateElectricity(Building b);
        bool repair();
        void update();

    private:
        bool working;
};

#endif 