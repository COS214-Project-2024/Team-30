#ifndef TAXBRACKET_H
#define TAXBRACKET_H
#include <iostream>
using namespace std;

class TaxBracket
{
    protected:
    int amountToPay;
    string type;

    public:
    
    virtual int getamountToPay() =0;
    virtual string getTaxBracket() =0;


};
#endif