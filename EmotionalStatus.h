#ifndef EMPLOYMENTSTATUS_H
#define EMPLOYMENTSTATUS_H
#include <iostream>
using namespace std;

class EmploymentStatus
{
    protected:
    int incomeOfEmployee;
    int hoursOfWorks;
    string jobType;

    public:
    
    virtual int getIncome()=0;
    virtual string getJobType() =0;


};
#endif