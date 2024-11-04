#ifndef CATEGORIZATIONSTRATEGY_H
#define CATEGORIZATIONSTRATEGY_H

#include <string>
#include "Government.h"
class Government;

/**
 * @class CategorizationStrategy
 * @brief Abstract base class for strategies used to categorize the city's growth status.
 *
 * This class provides an interface for defining various categorization strategies 
 * based on values managed by the `Government` class. Derived classes 
 * must implement the `categorize` function to determine the category of city growth.
 */
class CategorizationStrategy {
public:
    /**
     * @brief Categorizes the city based on the current state of the Government.
     *
     * This function is intended to be overridden by derived classes to provide 
     * specific categorization logic based on growth factors.
     * 
     * @param g Pointer to the `Government` object whose state is used for categorization.
     * @return A string representing the category of the city.
     */
    virtual std::string categorize(Government* g) = 0;

    /**
     * @brief Virtual destructor.
     *
     * Clean up of derived classes.
     */
    virtual ~CategorizationStrategy() = default;
};

#endif



// #ifndef CATEGORIZATIONSTRATEGY_H
// #define CATEGORIZATIONSTRATEGY_H

// #include <string>
// #include "Government.h"
// class Government;

// class CategorizationStrategy{
//     public:
//         virtual std::string categorize(Government* g)=0;  

// };

// #endif