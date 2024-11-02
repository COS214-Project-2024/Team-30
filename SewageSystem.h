#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "Building.h"

using namespace std;

class SewageSystem {
    public:
        SewageSystem();
        void setWorking(bool b);

        void manageDisposal(Building b);
        void manageTreatment(Building b);
        
        bool repair();

    private:
        bool working;
};

#endif 