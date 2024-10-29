#ifndef TAXBRACKET_H
#define TAXBRACKET_H



#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Citizen;

class TaxBracket
{
    public:
    virtual int getamountToPay() =0;
    virtual string getTaxBracket() =0;
    virtual void setTaxRate(double rate) = 0;
    double getTaxRate();
    virtual ~TaxBracket();

    protected:
    int amountToPay;
    string type;
    unique_ptr<Citizen> citizen;
    double taxRate;

};
#endif