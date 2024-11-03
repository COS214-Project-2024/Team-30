#ifndef CITIZEN_H
#define CITIZEN_H

#include "TaxBracket.h"
#include"EmploymentStatus.h"
#include "EmotionalState.h"
#include "Satisfied.h"
#include "Unsatisfied.h"
#include "OfficeJob.h"
#include "IndustrialJob.h"
#include "Unemployed.h"
#include "LowestTaxBracket.h"
#include "MiddleTaxBracket.h"
#include "HighestTaxBracket.h"

#include <iostream>
#include <string>
#include <memory>
#include <random>
using namespace std;

class Building;

class Citizen : public std::enable_shared_from_this<Citizen>
{
    private:
    int id;
    int income;
    int accountBalance;
    int happinessMeter;
    unique_ptr<TaxBracket> taxBracket;
    unique_ptr<EmploymentStatus> employmentStatus;
    unique_ptr<EmotionalState> emotionalState;
    shared_ptr<Building> home; 
    shared_ptr<Building> currentBuilding; 
    static int nextID; 

    public:
    Citizen();
    int payTax();
    string getEmploymentStatus();
    void payTaxes();
    void getPaid();
    int getAccountBalance();
    void assignToBuilding(shared_ptr<Building> building);
    void setHome(std::shared_ptr<Building> home);
    void reactToEmergency(int damage);
    int getHappinessMeter();
    int getID() const;
    int getIncome();
    shared_ptr<Building> getHome();
    string getEmotionalState();
    void setEmotionalState(unique_ptr<EmotionalState> emotionalState);
    void setEmploymentStatus(std::unique_ptr<EmploymentStatus> status);
    void setHappinessMeter(int happinessMeter);
    void printDetails(); //helper to see that constructor works as expected
    void respondToTax();
    void respondToPayment();
    void reactToNotGettingHired();
    void respondToJobChange(bool gainedJob);
    void respondToIncreasedInfrastructure();
    void getHired(std::unique_ptr<EmploymentStatus> newJob);
    void getFired();
    

    
    

};
#endif