#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Buildings.h"

using namespace std;

class WaterSupply {
    public:
        WaterSupply();

        void distributeWater(Building b);
        
        bool repair();

    private:
        bool working;
};

#endif 