#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H
#include "EmploymentStatus.h"

class Unemployed : public EmploymentStatus
{
    public:
    Unemployed();
    int getIncome() override;
    string getJobType() override;
    unique_ptr<EmploymentStatus> getEmploymentStatus() override;
    int getHoursOfWork() override;
};

#endif
