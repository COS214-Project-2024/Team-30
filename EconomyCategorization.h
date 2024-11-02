#ifndef ECONOMYSTRATEGY_H
#define ECONOMYSTRATEGY_H

#include <string>
#include "CategorizationStrategy.h"
#include "Government.h"

/**
 * @class EconomyCategorization
 * @brief A strategy class that categorizes the economic state of the city based on Government data.
 *
 * This class implements the `CategorizationStrategy` interface to provide a categorization strategy 
 * specifically for the economy of the city. The categorization is based on the data available from 
 * the `Government` object.
 */
class EconomyCategorization : public CategorizationStrategy {
public:
    /**
     * @brief Categorizes the economic state of the city.
     *
     * This function examines the current economic conditions within the city and returns a string 
     * representing the economic category (e.g., "Growing," "Stable," "Recession") based on factors 
     * such as population and employment rates from the `Government` instance.
     *
     * @param g A pointer to the `Government` object that provides the necessary data for categorization.
     * @return A string representing the economic category of the city.
     */
    std::string categorize(Government* g) override;
};

#endif



// #ifndef ECONOMYSTRATEGY_H
// #define ECONOMYSTRATEGY_H

// #include <string>

// #include "CategorizationStrategy.h"
// #include "Government.h"

// class EconomyCategorization : public CategorizationStrategy {
// public:
//     std::string categorize(Government* g) override;
// };

// #endif