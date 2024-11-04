#include "EconomyCategorization.h"

using namespace std;
/**
 * @brief Categorizes the economic state of the city based on the employment rate.
 *
 * This function retrieves the employment rate from the `Government` object to assess the 
 * current level of economic activity. It returns a string representing the economic 
 * category:
 * - "Low Economic Activity" if employment rate is below 45%
 * - "Medium Economic Activity" if employment rate is between 45% and 70%
 * - "High Economic Activity" if employment rate is above 70%
 *
 * @param g A pointer to the `Government` object that provides the employment rate data.
 * @return A string representing the economic activity level of the city.
 */
string EconomyCategorization::categorize(Government* g)
{
    double sta = g->getEmploymentRate();

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


// #include "EconomyCategorization.h"

// std::string EconomyCategorization::categorize(Government* g)
// {
//     double sta= g->getEmploymentRate();
//     // std::cout<<sta<<std::endl;
//     if (sta < 0.45)
//     {
//         return "Low Economic Activity";
//     }
//     else if (sta < 0.70)
//     {
//         return "Medium Economic Activity";
//     }
//     else
//     {
//         return "High Economic Activity";
//     }
// }
