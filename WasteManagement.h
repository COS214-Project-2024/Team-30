#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Buildings.h"

using namespace std;

class WasteManagement {
    public:
        WasteManagement();

        void removeWaste(Building b);
        void recycle(Building b);

        bool repair();

    private:
        bool working;
};

#endif 