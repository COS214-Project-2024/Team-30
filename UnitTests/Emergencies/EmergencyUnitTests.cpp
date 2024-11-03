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

TEST_CASE("Testing Emergency Event Impact on Building Health and Citizens") {
    // Create a residential building through the factory
    ResidentialFactory residentialFactory;
    auto residentialBuilding = std::shared_ptr<Building>(residentialFactory.createBuilding());

    // Initial setup: Verify the building's initial health
    residentialBuilding->setHealth(100);
    CHECK(residentialBuilding->getHealth() == 100);

    // Add citizens to the building
    auto citizen1 = std::make_shared<Citizen>();
    auto citizen2 = std::make_shared<Citizen>();
    citizen1->setHappinessMeter(100);
    citizen2->setHappinessMeter(100);
    citizen1->assignToBuilding(residentialBuilding);
    citizen2->assignToBuilding(residentialBuilding);

    // Simulate a fire emergency and check building's health decrease
    Fires fireEvent;
    fireEvent.accessDamage(residentialBuilding);

    // Verify that building health has decreased
    CHECK(residentialBuilding->getHealth() < 100);
    int healthAfterFire = residentialBuilding->getHealth();

    // Simulate an earthquake emergency and check further health decrease
    Earthquake earthquakeEvent;
    earthquakeEvent.accessDamage(residentialBuilding);

    // Verify that building health has decreased further
    CHECK(residentialBuilding->getHealth() < healthAfterFire);
    
    // Optionally, check citizens’ happiness change
    // For example, ensure it’s less than the initial happiness level
    int happiness1 = citizen1->getHappinessMeter();
    int happiness2 = citizen2->getHappinessMeter();
    CHECK(happiness1 < 100); // Assuming 100 is the initial happiness level
    CHECK(happiness2 < 100);

    // Output results for optional visibility during testing
    std::cout << "Building health after fire: " << healthAfterFire << std::endl;
    std::cout << "Building health after earthquake: " << residentialBuilding->getHealth() << std::endl;
    std::cout << "Citizen 1 happiness: " << happiness1 << std::endl;
    std::cout << "Citizen 2 happiness: " << happiness2 << std::endl;
}