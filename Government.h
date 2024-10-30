#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
class Government{
public:
    void attach(CityGrowthObserver* ob);
    void detach(CityGrowthObserver* ob);
    void notify();

    void populationGrowth(int newPeople);
    int getPopulation();

private:
    std::vector<CityGrowthObserver*> observers;
    CategorizationStrategy* strategy;
    int Population;
};

#endif