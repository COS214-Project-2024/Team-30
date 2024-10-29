#include "LowestTaxBracket.h"

LowestTaxBracket::LowestTaxBracket()
{
    taxRate = 0.1;
}
int LowestTaxBracket::getamountToPay()
{
    return citizen->getIncome() * taxRate;
}
string LowestTaxBracket::getTaxBracket()
{
    return "LowestTaxBracket";
}
void LowestTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}