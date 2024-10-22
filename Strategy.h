#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

class CategorizationStrategy{
    public:
        virtual std::string categorize(int population,int economy)=0;  

};

class PopulationCategorization : public CategorizationStrategy {
public:
    std::string categorize(int population, int economy) override;
};

class EconomyCategorization : public CategorizationStrategy {
public:
    std::string categorize(int population, int economy) override;
};

#endif