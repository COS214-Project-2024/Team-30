#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Building.h"
#include "ResourceObserver.h"
#include "Water.h"

using namespace std;

class WaterSupply : public ResourceObserver {
    public:
        WaterSupply();
        void setWorking(bool b);

        void distributeWater(Building b);
        
        bool repair();
        void updateResourceLevel();

    private:
        bool working;
};

#endif 