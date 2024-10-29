#include "MiddleTaxBracket.h"

MiddleTaxBracket::MiddleTaxBracket()
{
    taxRate = 0.35;
}
int MiddleTaxBracket::getamountToPay()
{
    return citizen->getIncome() * taxRate;
}
string MiddleTaxBracket::getTaxBracket()
{
    return "MiddleTaxBracket";
}
void MiddleTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}