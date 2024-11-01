#ifndef ECONOMYSTRATEGY_H
#define ECONOMYSTRATEGY_H

#include <string>

#include "CategorizationStrategy.h"
#include "Government.h"

class EconomyCategorization : public CategorizationStrategy {
public:
    std::string categorize(Government* g) override;
};

#endif