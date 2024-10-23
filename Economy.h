#ifndef ECONOMY_H
#define ECONOMY_H

#include "CityGrowthObserver.h"

class Economy : public CityGrowthObserver {
public:
    void update(int population) override;
};

#endif