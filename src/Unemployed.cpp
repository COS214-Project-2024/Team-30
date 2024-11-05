#include "Unemployed.h"

Unemployed::Unemployed()
{
    this->hoursOfWorks = 0;
    this->incomeOfEmployee = 0;
    this->jobType = "Unemployed";
}

int Unemployed::getIncome()
{
    return this->incomeOfEmployee;
}
int Unemployed::getHoursOfWork()
{
    return this->hoursOfWorks;
}
string Unemployed::getJobType()
{
    return jobType;
}
unique_ptr<EmploymentStatus> Unemployed::getEmploymentStatus()
{
    return make_unique<Unemployed>(); // Returns a new unique_ptr
}