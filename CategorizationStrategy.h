#ifndef CATEGORIZATIONSTRATEGY_H
#define CATEGORIZATIONSTRATEGY_H

#include <string>
#include "Government.h"
class Government;

class CategorizationStrategy{
    public:
        virtual std::string categorize(Government* g)=0;  

};

#endif