#ifndef MIDDLETAXBRACKET_H
#define MIDDLETAXBRACKET_H
#include <iostream>
#include "TaxBracket.h"
using namespace std;

class MiddleTaxBracket: public TaxBracket
{
    
    public:
    
     int getamountToPay() ;
     string getTaxBracket();


};
#endif