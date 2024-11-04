#ifndef POPULATIONSTRATEGY_H
#define POPULATIONSTRATEGY_H

#include <string>
#include "CategorizationStrategy.h"
#include "Government.h"

/**
 * @class PopulationCategorization
 * @brief Concrete strategy for categorizing population growth.
 * 
 * This class implements the `CategorizationStrategy` interface to provide a 
 * specific categorization based on population in the city.
 */
class PopulationCategorization : public CategorizationStrategy {
public:
    /**
     * @brief Categorizes the population based on criteria.
     * 
     * This method uses data from the `Government` class to determine 
     * and return a categorization of population growth.
     * 
     * @param g A pointer to the `Government` instance from which data is accessed.
     * @return A string representing the population category.
     */
    std::string categorize(Government* g) override;
};

#endif

// #ifndef POPULATIONSTRATEGY_H
// #define POPULATIONSTRATEGY_H

// #include <string>

// #include "CategorizationStrategy.h"
// #include "Government.h"

// class PopulationCategorization : public CategorizationStrategy {
// public:
//     std::string categorize(Government* g) override;
// };

// #endif