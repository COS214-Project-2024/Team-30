#ifndef POPULATIONSTRATEGY_H
#define POPULATIONSTRATEGY_H

#include <string>

#include "CategorizationStrategy.h"
#include "Government.h"

class PopulationCategorization : public CategorizationStrategy {
public:
    std::string categorize(Government* g) override;
};

#endif