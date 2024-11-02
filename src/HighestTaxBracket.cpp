#include "HighestTaxBracket.h"

/**
 * @brief Constructs a HighestTaxBracket with a predefined tax rate.
 *
 * This constructor initializes the tax rate for the HighestTaxBracket to 
 * 0.4 (40%).
 */
HighestTaxBracket::HighestTaxBracket()
{
    taxRate = 0.4;
}
/**
 * @brief Calculates the amount of tax to be paid based on the given income.
 *
 * This method computes the tax amount by multiplying the provided income 
 * by the tax rate of the HighestTaxBracket.
 *
 * @param income The income amount used to calculate the tax.
 * @return The calculated tax amount as an integer.
 */
int HighestTaxBracket::getamountToPay(int income)
{
    return income * taxRate;
}
/**
 * @brief Retrieves the name of the tax bracket.
 *
 * This method returns the string representation of the tax bracket, which 
 * is "HighestTaxBracket".
 *
 * @return A string indicating the tax bracket name.
 */
string HighestTaxBracket::getTaxBracket()
{
    return "HighestTaxBracket";
}
/**
 * @brief Sets a new tax rate for the HighestTaxBracket.
 *
 * This method allows the user to update the tax rate for the 
 * HighestTaxBracket to the specified value.
 *
 * @param rate The new tax rate to be set, as a double.
 */
void HighestTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}