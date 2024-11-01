#ifndef HOUSING_H
#define HOUSING_H

#include "CityGrowthObserver.h"

class Housing : public CityGrowthObserver {
public:
    void update(Government* g) override;
};

#endif