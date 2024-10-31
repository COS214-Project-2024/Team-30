#include <iostream>

//City Growth Observer includes
#include "Housing.h"
#include "Infrastructure.h"
#include "Economy.h"
#include "Government.h"

//CAtegorization includes
#include "CategorizationStrategy.h"
#include "PopulationCategorization.h"
#include "EconomyCategorization.h"

int main() {

    Government cityGovernment;
    PopulationCategorization popStrategy;

    //  observers
    Housing housingObserver;
    Infrastructure infrastructureObserver;
    Economy economyObserver;

    // Attach 
    cityGovernment.attach(&housingObserver);
    cityGovernment.attach(&infrastructureObserver);
    cityGovernment.attach(&economyObserver);

    //strategy
    cityGovernment.setStrategy(&popStrategy);

    //population growth
    cityGovernment.populationGrowth(1000); 
    std::cout << "City categorized as: " << cityGovernment.categorize() << std::endl;

    cityGovernment.populationGrowth(5000); 
    std::cout << "City categorized as: " << cityGovernment.categorize() << std::endl;

    return 0;
}
