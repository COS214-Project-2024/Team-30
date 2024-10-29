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

int main()
{
    const int numCitizens = 10;                 // Define the number of Citizen instances
    vector<Citizen> citizens(numCitizens); // Create a vector of Citizen objects


    for (int i = 0; i < numCitizens; i++)
    {
        citizens[i].printDetails();
        cout << "\n";
    }
    
}