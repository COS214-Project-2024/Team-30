#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include <iostream>
#include "Citizens.h"
#include <vector>
using namespace std;
class Government
{
private:

int CityBudget;
vector<Citizen *> Population;
Government* government;
double employeerate;
//CategorizationStrategy* strategy;
//vector<CityGrowthObserver *> observer;

public:
Government();
~Government();
void PopulationGrowth(Citizen*);
void collectTax();
double calculateEmploymentRate();
int purchaseBuildings();
void setTax();
void attach();
void detach();
void notify();



};
#endif