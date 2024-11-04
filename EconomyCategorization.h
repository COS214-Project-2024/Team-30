#ifndef ECONOMYSTRATEGY_H
#define ECONOMYSTRATEGY_H

#include <string>
#include "CategorizationStrategy.h"
#include "Government.h"

using namespace std;
/**
 * @class EconomyCategorization
 * @brief A strategy class that categorizes the economic state of the city based on Government data.
 *
 * This class implements the `CategorizationStrategy` interface to provide a categorization strategy 
 * specifically for the economy of the city.
 */
class EconomyCategorization : public CategorizationStrategy {
public:
    /**
     * @brief Categorizes the economic state of the city.
     *
     * This function examines an economic condition and returns a string appropriately.
     *
     * @param g A pointer to the `Government` object that provides the necessary data for categorization.
     * @return A string representing the economic category of the city.
     */
    string categorize(Government* g) override;
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