#ifndef INDUSTRIALJOB_H
#define INDUSTRIALJOB_H

#include "EmploymentStatus.h"

class IndustrialJob : public EmploymentStatus
{
    public:
    IndustrialJob();
    int getIncome() override;
    string getJobType() override;
    unique_ptr<EmploymentStatus> getEmploymentStatus() override;
    int getHoursOfWork() override;

};

#endif
