#ifndef LOWESTTAXBRACKET_H
#define LOWESTTAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
#include "Citizen.h"
using namespace std;

class LowestTaxBracket : public TaxBracket
{

public:
    LowestTaxBracket();
    int getamountToPay(int income) override;
    string getTaxBracket() override;
    void setTaxRate(double rate) override;

};
#endif