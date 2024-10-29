#include "HighestTaxBracket.h"

HighestTaxBracket::HighestTaxBracket()
{
    taxRate = 0.4;
}
int HighestTaxBracket::getamountToPay()
{
    return citizen->getIncome() * taxRate;
}
string HighestTaxBracket::getTaxBracket()
{
    return "HighestTaxBracket";
}
void HighestTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}