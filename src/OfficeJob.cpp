#include "OfficeJob.h"

    OfficeJob::OfficeJob()
    {
        this->hoursOfWorks = 8;
        this->incomeOfEmployee = 9000;
        this->jobType = "OfficeJob";
    }
    int OfficeJob::getIncome()
    {
        return this->incomeOfEmployee;
    }
    string OfficeJob::getJobType()
    {
        return this->jobType;
    }
    unique_ptr<EmploymentStatus> OfficeJob::getEmploymentStatus(){
        return make_unique<OfficeJob>(); // Returns a new unique_ptr
    }
    int OfficeJob::getHoursOfWork()
    {
        return this->hoursOfWorks;
    }