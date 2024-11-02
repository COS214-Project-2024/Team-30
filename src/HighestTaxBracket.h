#ifndef HIGHESTTAXBRACKET_H
#define HIGHESTTAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
#include "Citizen.h"


using namespace std;

class HighestTaxBracket: public TaxBracket
{
    
    public:
     HighestTaxBracket();
     int getamountToPay(int income) override;
     string getTaxBracket() override;
    void setTaxRate(double rate) override;

};
#endif