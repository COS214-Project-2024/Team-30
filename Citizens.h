#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include "TaxBracket.h"
#include"EmploymentStatus.h"
#include "EmotionalState.h"
using namespace std;
class Citizen
{
    private:
    int income;
    TaxBracket* TaxBracket;
    EmploymentStatus* EmploymentStatus;
    EmotionalState* emotionalState;

    public:

    int payTax();
    void goToWork();
    void callEmergencyServices();
    void update();
    void request();

};
#endif