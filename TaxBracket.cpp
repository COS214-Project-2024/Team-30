#include "TaxBracket.h"
#include "CitizensUnitTests/Citizen.h"
  

/**
 * @brief Retrieves the tax rate associated with the TaxBracket.
 *
 * This method returns the current tax rate for the TaxBracket object.
 *
 * @return The tax rate as a double.
 */
double TaxBracket::getTaxRate()
{
    return taxRate;   
}
/**
 * @brief Destructor for the TaxBracket class.
 *
 * This destructor is called when an instance of TaxBracket is destroyed. 
 * It performs any necessary cleanup operations.
 */
TaxBracket::~TaxBracket(){}