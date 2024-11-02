#ifndef CATEGORIZATIONSTRATEGY_H
#define CATEGORIZATIONSTRATEGY_H

#include <string>

class CategorizationStrategy{
    public:
        virtual std::string categorize(int population,int economy)=0;  

};

#endif