#ifndef ECONOMYSTRATEGY_H
#define ECONOMYSTRATEGY_H

#include <string>

#include "CategorizationStrategy.h"

class EconomyCategorization : public CategorizationStrategy {
public:
    std::string categorize(int population, int economy) override;
};

#endif