#include "Government.h"
#include <vector>
#include <iostream>

void Government::attach(CityGrowthObserver *ob)
{
    observers.push_back(ob);
}

void Government::detach(CityGrowthObserver *ob)
{
    for (auto it = observers.begin(); it != observers.end(); ++it)
    {
        if (*it == ob)
        {
            observers.erase(it);
            break; 
        }
    }
}

void Government::notify()
{
    for (CityGrowthObserver *observer : observers)
    {
        observer->update(Population);
    }
}

std::string Government::categorize()
{
    return strategy->categorize(Population, 0);
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