#ifndef HIGHESTTAXBRACKET_H
#define HIGHESTTAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
using namespace std;

class HighestTaxBracket: public TaxBracket
{
    
    public:
    
     int getamountToPay() ;
     string getTaxBracket();


};
#endif