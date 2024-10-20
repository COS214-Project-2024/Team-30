#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H
#include <iostream>
#include"EmploymentStatus.h"
using namespace std;

class Unemployed:public EmploymentStatus
{
    
    public:
    
    virtual int getIncome();
    virtual string getJobType();


};
#endif