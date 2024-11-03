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
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "CityGrowthObserver.h"
#include "CategorizationStrategy.h"
#include "Citizen.h"
using namespace std;

class CityGrowthObserver;
class CategorizationStrategy;
class Government{
private:
//lists
    //vector<std::shared_ptr<CityGrowthObserver>> observers;
    vector<std::shared_ptr<Citizen>> population;
    vector<std::shared_ptr<Building>> infrastructure;
    std::vector<CityGrowthObserver*> observers;

//objects 
    ResidentialFactory residentialFactory;
    CommercialFactory commercialFactory;
    IndustrialFactory industrialFactory;
    CategorizationStrategy* strategy;
    //unique_ptr<CategorizationStrategy> strategy;
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
    void populationDecline(int i);
    void collectTaxes();
    void printInfo();
    void payDay();
    void jobOpportunities();
    void printCitizenSummary();
    double populationSatisfactionRate();
    vector<std::shared_ptr<Citizen>> getPeople ();
    vector<std::shared_ptr<Building>> getInfrastructure();
    ~Government();

    //citygrowth observer
    void attach(CityGrowthObserver* ob);
    void detach(CityGrowthObserver* ob);
    void notifyObservers();

     //
    void setStrategy(CategorizationStrategy* str);
    void setCityBudget(int budget);
    int getCityBudget();
    std::string categorize();

    //
    int getPopulationNum();
    int getNumberofUnemployedCitizens();
    int getNumberOfEmployedCitizens();
    double getEmploymentRate();
    int ResidentialCapacity();
};

#endif