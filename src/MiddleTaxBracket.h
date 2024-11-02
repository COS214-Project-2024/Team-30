#ifndef MIDDLETAXBRACKET_H
#define MIDDLETAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
#include "Citizen.h"



using namespace std;

class MiddleTaxBracket : public TaxBracket
{

public:
    MiddleTaxBracket();
    int getamountToPay(int income) override;
    string getTaxBracket() override;
    void setTaxRate(double rate) override;
};
#endif