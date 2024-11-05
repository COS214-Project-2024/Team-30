#include "LowestTaxBracket.h"

/**
 * @brief Constructs a LowestTaxBracket with a predefined tax rate.
 *
 * This constructor initializes the tax rate for the LowestTaxBracket to 
 * 0.1 (10%).
 */
LowestTaxBracket::LowestTaxBracket()
{
    taxRate = 0.1;
}
/**
 * @brief Calculates the amount of tax to be paid based on the given income.
 *
 * This method computes the tax amount by multiplying the provided income 
 * by the tax rate of the LowestTaxBracket.
 *
 * @param income The income amount used to calculate the tax.
 * @return The calculated tax amount as an integer.
 */
int LowestTaxBracket::getamountToPay(int income)
{
    return income * taxRate;
}
/**
 * @brief Retrieves the name of the tax bracket.
 *
 * This method returns the string representation of the tax bracket, which 
 * is "LowestTaxBracket".
 *
 * @return A string indicating the tax bracket name.
 */
string LowestTaxBracket::getTaxBracket()
{
    return "LowestTaxBracket";
}
/**
 * @brief Sets a new tax rate for the LowestTaxBracket.
 *
 * This method allows the user to update the tax rate for the 
 * LowestTaxBracket to the specified value.
 *
 * @param rate The new tax rate to be set, as a double.
 */
void LowestTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}