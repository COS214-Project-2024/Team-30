#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../src/Citizen.h"
#include "../../src/Building.h"
#include "../../src/Residential.h"
#include "../../src/Government.h"
#include "../../src/Fires.h"
#include "../../src/Earthquake.h"
#include "../../src/Building.h"
#include "../../src/EmergencyServices.h"
#include "../../src/Emergencies.h"
#include "../../src/Thieves.h"
#include "../../src/PopulationCategorization.h"
#include "../../src/EconomyCategorization.h"
#include "../../src/Housing.h"
#include "../../src/Infrastructure.h"
#include "../../src/Economy.h"
#include "../../src/PopulationGrowth.h"

TEST_CASE("Government class tests") {
    Government city("SampleCity");

    // Test initial state of the city
    CHECK(city.getPopulationNum() == 0);
    CHECK(city.getEmploymentRate() == 0.0);
    CHECK(city.ResidentialCapacity() == 0);

    // Create citizens
    auto citizen1 = std::make_shared<Citizen>();
    auto citizen2 = std::make_shared<Citizen>();

    // Add citizens to the city
    city.populationGrowth(citizen1);
    city.populationGrowth(citizen2);

    CHECK(city.getPopulationNum() == 2);
    CHECK(city.getNumberOfEmployedCitizens() + city.getNumberofUnemployedCitizens() == city.getPopulationNum());
 

    // Test employment rate calculation
    citizen1->setEmploymentStatus(std::make_unique<OfficeJob>());
    citizen2->setEmploymentStatus(std::make_unique<Unemployed>());
    city.calculateEmploymentRate();
    CHECK(city.getEmploymentRate() == 0.5);

    // Test infrastructure increase
    city.setCityBudget(1000);
    city.increaseInfurstructure();
    CHECK(city.getInfrastructure().size() > 0); // should have buildings

    // Test taxes collection
    city.collectTaxes();
    CHECK(city.getCityBudget() > 0); // check if budget has increased

    // Test population satisfaction rate
    citizen1->setEmotionalState(std::make_unique<Satisfied>());
    citizen2->setEmotionalState(std::make_unique<Unsatisfied>());
    CHECK(city.populationSatisfactionRate() == 0.5);

    // Test print citizen summary
    city.printCitizenSummary();

}

