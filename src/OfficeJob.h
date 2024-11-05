#ifndef OFFICEJOB_H
#define OFFICEJOB_H
#include "EmploymentStatus.h"

class OfficeJob : public EmploymentStatus
{
    public:
    OfficeJob();
    int getIncome() override;
    string getJobType() override;
    unique_ptr<EmploymentStatus> getEmploymentStatus() override; 
    int getHoursOfWork() override;

};

#endif
