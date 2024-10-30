#include "MiddleTaxBracket.h"

MiddleTaxBracket::MiddleTaxBracket()
{
    taxRate = 0.35;
}
int MiddleTaxBracket::getamountToPay(int income)
{
    int amounttopay = income * taxRate;
    return amounttopay;
}
string MiddleTaxBracket::getTaxBracket()
{
    return "MiddleTaxBracket";
}
void MiddleTaxBracket::setTaxRate(double rate)
{
    this->taxRate = rate;
}