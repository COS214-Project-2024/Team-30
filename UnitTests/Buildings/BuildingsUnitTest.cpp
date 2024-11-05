#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../src/Citizen.h"
#include "../../src/Building.h"
#include "../../src/Residential.h"
#include "../../src/Commercial.h"
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
#include "../../src/Built.h"
#include "../../src/Underconstruction.h"
#include "../../src/Destroyed.h"


TEST_CASE("Testing Building::setState") {
    Residential building;

    SUBCASE("Setting Building to Built state") {
        building.setState(std::make_unique<Built>());
        CHECK(building.getState()->getStatus() == "Built");
    }

    SUBCASE("Setting Building to Underconstruction state") {
        building.setState(std::make_unique<Underconstruction>());
        CHECK(building.getState()->getStatus() == "Underconstruction");
    }

    SUBCASE("Setting Building to Destroyed state") {
        building.setState(std::make_unique<Destroyed>());
        CHECK(building.getState()->getStatus() == "Destroyed");
    }
}

TEST_CASE("TESTING BUILDINGS HEALTH")
{
    CommercialFactory c;
    unique_ptr<Building> building= c.createBuilding();
    CHECK(building->getHealth() == 100);
    building->takeDamage(30);
    CHECK(building->getHealth() == 70);
    building->takeDamage(70);
    CHECK(building->getHealth() == 0);
    CHECK(building->getState()->getStatus() == "Destroyed");

    Residential resBuilding;
    resBuilding.setCapacity(2);
    CHECK(resBuilding.getCapacity() == 2);
    
    auto citizen1 = std::make_shared<Citizen>();
    auto citizen2 = std::make_shared<Citizen>();
    resBuilding.addCitizen(citizen1);
    resBuilding.addCitizen(citizen2);
    CHECK(resBuilding.hasOccupant(citizen1->getID()));
    CHECK(resBuilding.hasOccupant(citizen2->getID()));
    auto citizen3 = std::make_shared<Citizen>();
    resBuilding.addCitizen(citizen3);
    CHECK(resBuilding.getCapacity() == 2);
}

