#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <random>
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
#include "Citizen.h"
#include "Building.h"
#include "BuildingFactory.h"
using namespace std;
class Government{
private:
//lists
    std::vector<CityGrowthObserver*> observers;
    std::vector<Citizen*> population;
    std::vector<Building*> Infurstructure;
//objects
    BuildingFactory* CityBuilder;
    CategorizationStrategy* strategy;
//data    
    string cityName;
    double employmentRate;
    int citybudget;


public:
    Government(string);
    void attach(CityGrowthObserver ob);
    void detach(CityGrowthObserver ob);
    void notifyObservers();
    void populationGrowth(Citizen*);
    void calculateEmploymentRate();
    void increaseInfurstructure();
    




};

#endif