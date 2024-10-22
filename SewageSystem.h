#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "Buildings.h"

using namespace std;

class SewageSystem {
    public:
        SewageSystem();

        void manageDisposal(Building b);
        void manageTreatment(Building b);
        
        bool repair();

    private:
        bool working;
};

#endif 