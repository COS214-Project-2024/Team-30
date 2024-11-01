#include "MiddleTaxBracket.h"
/**
 * @brief Constructs a MiddleTaxBracket with a predefined tax rate.
 *
 * This constructor initializes the tax rate for the MiddleTaxBracket to 
 * 0.35 (35%).
 */
MiddleTaxBracket::MiddleTaxBracket()
{
    taxRate = 0.35;
}
/**
 * @brief Calculates the amount of tax to be paid based on the given income.
 *
 * This method computes the tax amount by multiplying the provided income 
 * by the tax rate of the MiddleTaxBracket.
 *
 * @param income The income amount used to calculate the tax.
 * @return The calculated tax amount as an integer.
 */
int MiddleTaxBracket::getamountToPay(int income)
{
    int amounttopay = income * taxRate;
    return amounttopay;
}
/**
 * @brief Retrieves the name of the tax bracket.
 *
 * This method returns the string representation of the tax bracket, which 
 * is "MiddleTaxBracket".
 *
 * @return A string indicating the tax bracket name.
 */
string MiddleTaxBracket::getTaxBracket()
{
    return "MiddleTaxBracket";
}
/**
 * @brief Sets a new tax rate for the MiddleTaxBracket.
 *
 * This method allows the user to update the tax rate for the 
 * MiddleTaxBracket to the specified value.
 *
 * @param rate The new tax rate to be set, as a double.
 */
void MiddleTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}