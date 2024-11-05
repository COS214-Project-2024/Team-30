#ifndef EMPLOYMENTSTATUS_H
#define EMPLOYMENTSTATUS_H



#include <iostream>
#include <string>
#include <memory>
using namespace std;

class EmploymentStatus
{
protected:
    int incomeOfEmployee;
    int hoursOfWorks;
    string jobType;

public:
    virtual int getIncome() = 0;
    virtual int getHoursOfWork() = 0;
    virtual string getJobType() = 0;
    virtual unique_ptr<EmploymentStatus> getEmploymentStatus() = 0;
    //general methods that government will have control
    void setIncome(int incomeOfEmployee);
    void setHoursOfWork(int hoursOfWork);
    virtual ~EmploymentStatus();
};
#endif