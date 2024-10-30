#include "PopulationCategorization.h"

std::string PopulationCategorization::categorize(int population, int economy)
{
    if (population < 5000)
    {
        return "Small City";
    }
    else if (population < 50000)
    {
        return "Medium City";
    }
    else
    {
        return "Large City";
    }
}
