#include "IndustrialJob.h"

    IndustrialJob::IndustrialJob()
    {
        this->incomeOfEmployee = 4700;
        this->hoursOfWorks = 12;
        this->jobType = "IndustrialJob";
    }
    int IndustrialJob::getIncome()
    {
        return incomeOfEmployee;
    }
    string IndustrialJob::getJobType()
    {
        return jobType;
    }
    unique_ptr<EmploymentStatus> IndustrialJob::getEmploymentStatus()
    {
        return make_unique<IndustrialJob>();
    }
    int IndustrialJob::getHoursOfWork()
    {
        return hoursOfWorks;
    }