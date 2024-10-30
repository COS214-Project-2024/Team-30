#include "EconomyCategorization.h"

std::string EconomyCategorization::categorize(int population, int economy)
{
    if (economy < 10000)
    {
        return "Low Economic Activity";
    }
    else if (economy < 50000)
    {
        return "Medium Economic Activity";
    }
    else
    {
        return "High Economic Activity";
    }
}
