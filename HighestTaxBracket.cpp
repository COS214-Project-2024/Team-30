#include "HighestTaxBracket.h"

HighestTaxBracket::HighestTaxBracket()
{
    taxRate = 0.4;
}
int HighestTaxBracket::getamountToPay(int income)
{
    return income * taxRate;
}
string HighestTaxBracket::getTaxBracket()
{
    return "HighestTaxBracket";
}
void HighestTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}