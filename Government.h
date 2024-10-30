#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
class Government{
public:
    void attach(CityGrowthObserver ob);
    void detach(CityGrowthObserver ob);
    void notifyObservers();

private:
    std::vector<CityGrowthObserver*> observers;
    CategorizationStrategy* strategy;
};

#endif