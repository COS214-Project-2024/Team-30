#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include "TaxBracket.h"
#include"EmploymentStatus.h"
using namespace std;
class Citizen
{
    private:
    int income;
    TaxBracket* TaxBracket;
    EmploymentStatus* EmploymentStatus;
    int emotionalState;

    public:
    nhag`jhGHJGSS

    int PayTax();
    void GoToWork();
    void CallEmergencyServices();
    void update();
    void request();

};
#endif