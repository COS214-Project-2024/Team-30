#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Building.h"

using namespace std;

class WasteManagement {
    public:
        WasteManagement();
        void setWorking(bool b);

        void removeWaste(Building b);
        void recycle(Building b);

        bool repair();

    private:
        bool working;
};

#endif 