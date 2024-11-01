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

int main() {
    const int numCitizens = 100;
    Government government("CityGov");

    // Add citizens
    for (int i = 0; i < numCitizens; i++) {
        auto citizen = std::make_shared<Citizen>();
        government.populationGrowth(citizen);
    }
    

    government.collectTaxes();
    government.calculateEmploymentRate();

    // Set up strategies
    std::unique_ptr<CategorizationStrategy> popStrategy = std::make_unique<PopulationCategorization>();
    std::unique_ptr<CategorizationStrategy> ecoStrategy = std::make_unique<EconomyCategorization>();
    government.setStrategy(popStrategy.get());

    // Attach observers
    Housing housingObserver;
    Infrastructure infrastructureObserver;
    Economy economyObserver;
    government.attach(&housingObserver);
    government.attach(&infrastructureObserver);
    government.attach(&economyObserver);

    government.printInfo();
    std::cout<<std::endl;

    // Use categorization
    std::cout << "City categorization by Population: " << government.categorize() << std::endl;
    government.setStrategy(ecoStrategy.get());
    std::cout << "City categorization by Economy: " << government.categorize() << std::endl;
    

    for (int i = 0; i < 1000; i++) {
        auto citizen = std::make_shared<Citizen>();
        government.populationGrowth(citizen);
    }

    government.notifyObservers();
    std::cout << "City categorization by Population: " << government.categorize() << std::endl;
    government.setStrategy(ecoStrategy.get());
    std::cout << "City categorization by Economy: " << government.categorize() << std::endl;

    return 0;
}



// #include <iostream>

// //City Growth Observer includes
// #include "Housing.h"
// #include "Infrastructure.h"
// #include "Economy.h"
// #include "Government.h"
// #include "CityGrowthObserver.h"

// //CAtegorization includes
// #include "CategorizationStrategy.h"
// #include "PopulationCategorization.h"
// #include "EconomyCategorization.h"

// int main() {

//     // const int numCitizens = 100;                    // Define the number of Citizen instances
//     // std::vector<std::shared_ptr<Citizen>> citizens; // Vector of shared_ptrs to Citizen
//     // Government government("CityGov");

//     // for (int i = 0; i < numCitizens; i++)
//     // {
//     //     auto citizen = std::make_shared<Citizen>(); // Create a shared_ptr to a new Citizen
//     //     citizens.push_back(citizen);                // Store shared_ptr in the vector
//     //     government.populationGrowth(citizen);       // Pass shared_ptr to populationGrowth
//     // }

//     // PopulationCategorization popStrategy;

//     // //  observers
//     // Housing housingObserver;
//     // Infrastructure infrastructureObserver;
//     // Economy economyObserver;

//     // // Attach 
//     // government.attach(&housingObserver);
//     // government.attach(&infrastructureObserver);
//     // government.attach(&economyObserver);

//     // //strategy
//     // government.setStrategy(&popStrategy);


//     // government.printInfo();

//     // //population growth
//     // std::cout << "City categorized as: " << government.categorize() << std::endl;

//     // return 0;

//     const int numCitizens = 100;
//     std::vector<std::shared_ptr<Citizen>> citizens;
//     Government government("CityGov");

//     for (int i = 0; i < numCitizens; i++) {
//         auto citizen = std::make_shared<Citizen>();
//         citizens.push_back(citizen);
//         government.populationGrowth(citizen);
//     }

//     PopulationCategorization popStrategy;
//     government.setStrategy(&popStrategy);

//     Housing housingObserver;
//     Infrastructure infrastructureObserver;
//     Economy economyObserver;

//     government.attach(&housingObserver);
//     government.attach(&infrastructureObserver);
//     government.attach(&economyObserver);

//     std::cout << "City Categorization: " << government.categorize() << std::endl;

//     return 0;
// }
