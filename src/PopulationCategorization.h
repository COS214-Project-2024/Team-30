#ifndef POPULATIONSTRATEGY_H
#define POPULATIONSTRATEGY_H

#include <string>

#include "CategorizationStrategy.h"

class PopulationCategorization : public CategorizationStrategy {
public:
    std::string categorize(int population, int economy) override;
};

#endif