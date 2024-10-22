#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Buildings.h"
#include "ResourceObserver.h"

using namespace std;

class WaterSupply : public ResourceObserver {
    public:
        WaterSupply();

        void distributeWater(Building b);
        
        bool repair();
        void update();

    private:
        bool working;
};

#endif 