#ifndef OFFICEJOB_H
#define OFFICEJOB_H
#include <iostream>
#include"EmploymentStatus.h"
using namespace std;

class OfficeJob:public EmploymentStatus
{
    
    public:
    
    virtual int getIncome();
    virtual string getJobType();


};
#endif