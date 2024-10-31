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
#include "Building.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "Underconstruction.h"
#include "Built.h"
#include "Destroyed.h"

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

     // Create factories
    ResidentialFactory residentialFactory;
    CommercialFactory commercialFactory;
    IndustrialFactory industrialFactory;
    LandmarkFactory landmarkFactory;

    // Create buildings using factories with smart pointers
    unique_ptr<Building> residentialBuilding = residentialFactory.createBuilding();
    unique_ptr<Building> commercialBuilding = commercialFactory.createBuilding();
    unique_ptr<Building> industrialBuilding = industrialFactory.createBuilding();
    unique_ptr<Building> landmarkBuilding = landmarkFactory.createBuilding();

    residentialBuilding->displayInfo();
    commercialBuilding->displayInfo();
    industrialBuilding->displayInfo();
    landmarkBuilding->displayInfo();

    cout << "\n\n\n" << "PROTOTYPE" << "\n\n\n";

    unique_ptr<Building> residentialBuilding2 = residentialBuilding->clone();
    residentialBuilding2->setState(make_unique<Built>());
    residentialBuilding2->displayInfo();
    cout << "\n\n";
    residentialBuilding->displayInfo();

}