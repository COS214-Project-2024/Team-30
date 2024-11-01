#ifndef POPULATIONGROWTH_H
#define POPULATIONGROWTH_H

#include "CityGrowthObserver.h"

class PopulationGrowth : public CityGrowthObserver {
public:
    void update(Government* g) override;
    void printInfo(Government* g);
private:
    int oldPop=0; 
    double bR;
};

#endif