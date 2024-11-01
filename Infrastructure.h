#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "CityGrowthObserver.h"

class Infrastructure : public CityGrowthObserver {
public:
    void update(Government* g) override;
};

#endif