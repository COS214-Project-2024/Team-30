#ifndef LOWESTTAXBRACKET_H
#define LOWESTTAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
using namespace std;

class LowestTaxBracket: public TaxBracket
{
    
    public:
    
     int getamountToPay() ;
     string getTaxBracket();

//
};
#endif