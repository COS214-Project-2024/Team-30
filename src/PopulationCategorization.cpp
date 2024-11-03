#include "PopulationCategorization.h" 

/**
 * @brief Categorizes a government entity based on its population.
 *
 * This function takes a pointer to a Government object and evaluates 
 * its population number to categorize it into one of three categories:
 * "Small City", "Medium City", or "Large City".
 *
 * @param g Pointer to a Government object whose population is to be evaluated.
 * @return A string representing the category of the city based on its population.
 *         - "Small City" if population is less than 5000,
 *         - "Medium City" if population is between 5000 and 49999,
 *         - "Large City" if population is 50000 or more.
 */
std::string PopulationCategorization::categorize(Government* g)
{
    int population = g->getPopulationNum();
    
    if (population < 6)
    {
        return "Small City";
    }
    else if (population < 15)
    {
        return "Medium City";
    }
    else
    {
        return "Large City";
    }
}

// #include "PopulationCategorization.h"

// std::string PopulationCategorization::categorize(Government* g)
// {
//     int population =g->getPopulationNum();
    
//     if (population < 5000)
//     {
//         return "Small City";
//     }
//     else if (population < 50000)
//     {
//         return "Medium City";
//     }
//     else
//     {
//         return "Large City";
//     }
// }