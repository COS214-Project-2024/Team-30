#include "Government.h"
#include <vector>
#include <iostream>

void Government::attach(CityGrowthObserver *ob)
{
    observers.push_back(ob);
}

void Government::detach(CityGrowthObserver *ob)
{
    observers.erase(std::remove(observers.begin(), observers.end(), ob), observers.end());
}

void Government::notify()
{
    for (CityGrowthObserver *observer : observers)
    {
        observer->update(Population);
    }
}

void Government::populationGrowth(int newPeople)
{
    Population += newPeople;
    std::cout << "Population has grown to: " << Population << std::endl;
    notify();
}

int Government::getPopulation()
{
    return this->Population;
}