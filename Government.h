#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
#include "Citizen.h"
// #include "Building.h"
// #include "BuildingFactory.h"

using namespace std;
class CityGrowthObserver;
class CategorizationStrategy;

class Government{
private:
//lists
    std::vector<CityGrowthObserver*> observers;
    vector<std::shared_ptr<Citizen>> population;
    // vector<std::shared_ptr<Building>> infrastructure;

//objects 
    // unique_ptr<BuildingFactory> cityBuilder;
    CategorizationStrategy* strategy;
//data    
    string cityName;
    double employmentRate;
    int citybudget;
    int populationNum;


public:
    Government(string);
    
    void populationGrowth(std::shared_ptr<Citizen> );
    void calculateEmploymentRate();
    void increaseInfurstructure();
    void populationDecline(std::shared_ptr<Citizen>);
    void collectTaxes();
    void printInfo();
    double populationSatisfactionRate();
    ~Government();

    //citygrowth observer
    void attach(CityGrowthObserver* ob);
    void detach(CityGrowthObserver* ob);
    void notifyObservers();

    //
    void setStrategy(CategorizationStrategy* str);
    std::string categorize();

    //
    int getPopulationNum();
    double getEmploymentRate();

};

#endif