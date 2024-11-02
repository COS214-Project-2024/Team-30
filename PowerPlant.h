#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"
#include "ResourceObserver.h"
#include "Coal.h"

using namespace std;

class PowerPlant : public ResourceObserver {
    public:
        PowerPlant();
        void setWorking(bool b);

        void generateElectricity(Building b);

        bool repair();
        void updateResourceLevel();

    private:
        bool working;
};

#endif 