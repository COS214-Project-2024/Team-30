#include "EconomyCategorization.h"

std::string EconomyCategorization::categorize(Government* g)
{
    double sta= g->getEmploymentRate();
    // std::cout<<sta<<std::endl;
    if (sta < 0.45)
    {
        return "Low Economic Activity";
    }
    else if (sta < 0.70)
    {
        return "Medium Economic Activity";
    }
    else
    {
        return "High Economic Activity";
    }
}
