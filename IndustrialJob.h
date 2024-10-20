#ifndef INDUSTRIALJOB_H
#define INDUSTRIALJOB_H
#include <iostream>
#include"EmploymentStatus.h"
using namespace std;

class IndustrialJob:public EmploymentStatus
{
    
    public:
    
    virtual int getIncome();
    virtual string getJobType();


};
#endif