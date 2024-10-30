#include <iostream>
#include <memory>
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
#include "Government.h"

int main()
{
    const int numCitizens = 100;                    // Define the number of Citizen instances
    std::vector<std::shared_ptr<Citizen>> citizens; // Vector of shared_ptrs to Citizen
    Government government("CityGov");

    for (int i = 0; i < numCitizens; i++)
    {
        auto citizen = std::make_shared<Citizen>(); // Create a shared_ptr to a new Citizen
        citizens.push_back(citizen);                // Store shared_ptr in the vector
        government.populationGrowth(citizen);       // Pass shared_ptr to populationGrowth
    }

    government.collectTaxes();
    government.calculateEmploymentRate();
    government.printInfo();
}