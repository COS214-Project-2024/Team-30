#include <iostream>
#include <memory>
#include "Government.h"
#include "PopulationCategorization.h"
#include "EconomyCategorization.h"
#include "Housing.h"
#include "Infrastructure.h"
#include "Economy.h"
#include "Citizen.h"
#include "EmploymentStatus.h"
#include "EmotionalState.h"
#include "Satisfied.h"
#include "Unsatisfied.h"
#include "OfficeJob.h"
#include "IndustrialJob.h"
#include "Unemployed.h"
#include "TaxBracket.h"
#include "LowestTaxBracket.h"
#include "MiddleTaxBracket.h"
#include "HighestTaxBracket.h"
#include "PopulationGrowth.h"

int main() {
    const int numCitizens = 1000;
    Government government("CityGov");

    // Attach observers
    Housing housingObserver;
    Infrastructure infrastructureObserver;
    Economy economyObserver;
    PopulationGrowth populationObserver;

    government.attach(&populationObserver);
    government.attach(&housingObserver);
    government.attach(&infrastructureObserver);
    government.attach(&economyObserver);

    // Set up strategies
    std::unique_ptr<CategorizationStrategy> popStrategy = std::make_unique<PopulationCategorization>();
    std::unique_ptr<CategorizationStrategy> ecoStrategy = std::make_unique<EconomyCategorization>();

    // Add citizens
    for (int i = 0; i < numCitizens; i++) {
        auto citizen = std::make_shared<Citizen>();
        government.populationGrowth(citizen);
    }
    government.collectTaxes();
    government.notifyObservers();
    
    //Categorize
    government.setStrategy(popStrategy.get());
    std::cout << "City categorization by Population: " << government.categorize() << std::endl;
    government.setStrategy(ecoStrategy.get());
    std::cout << "City categorization by Economy: " << government.categorize() << std::endl;

    std::cout<<"=========================================================================================================="<<std::endl;

    for (int i = 0; i < 100; i++) {
        auto citizen = std::make_shared<Citizen>();
        government.populationGrowth(citizen);
    }
    government.collectTaxes();
    government.notifyObservers();

    std::cout << "City categorization by Population: " << government.categorize() << std::endl;
    government.setStrategy(ecoStrategy.get());
    std::cout << "City categorization by Economy: " << government.categorize() << std::endl;

    return 0;
}