#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
#include "Citizen.h"
#include "Building.h"
#include "BuildingFactory.h"
using namespace std;
class Government{
private:
//lists
    vector<std::shared_ptr<CityGrowthObserver>> observers;
    vector<std::shared_ptr<Citizen>> population;
    vector<std::shared_ptr<Building>> infrastructure;

// objects owned by Government
    unique_ptr<BuildingFactory> cityBuilder;
    unique_ptr<CategorizationStrategy> strategy;
//data    
    string cityName;
    double employmentRate;
    int citybudget;
    int populationNum;


public:
    Government(string);
    void attach(std::shared_ptr<CityGrowthObserver> ob);
    void detach(std::shared_ptr<CityGrowthObserver> ob);
    void notifyObservers();
    void populationGrowth(std::shared_ptr<Citizen> );
    void calculateEmploymentRate();
    void increaseInfurstructure();
    void populationDecline(std::shared_ptr<Citizen>);
    void collectTaxes();
    void printInfo();
    ~Government();




};

#endif