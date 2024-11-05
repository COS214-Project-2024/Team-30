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

TEST_CASE("Citizen Constructor initializes with default values") {
    Citizen citizen;

    // Check if ID starts as expected (assuming it starts from 1)
    CHECK(citizen.getID() == 1);

    // Check that account balance is initialized to 0
    CHECK(citizen.getAccountBalance() >= 0);

    // Check if happiness is within the 0-100 range
    CHECK(citizen.getHappinessMeter() >= 0);
    CHECK(citizen.getHappinessMeter() <= 100);

    // Check that employment status and emotional state are not empty
    CHECK(!citizen.getEmploymentStatus().empty());
    CHECK(!citizen.getEmotionalState().empty());
}

TEST_CASE("Citizen getPaid increases account balance by income") {
    Citizen citizen;

    int initialBalance = citizen.getAccountBalance();
    int income = citizen.getIncome();
    citizen.getPaid();

    // After calling getPaid, the account balance should have increased by the income
    CHECK(citizen.getAccountBalance() == initialBalance + income);
}

TEST_CASE("Citizen respondToTax adjusts happiness appropriately") {
    Citizen citizen;
    
    int initialHappiness = citizen.getHappinessMeter();

    // If unemployed, a higher penalty should apply
    if (citizen.getEmploymentStatus() == "Unemployed") {
        citizen.respondToTax();
        CHECK(citizen.getHappinessMeter() == std::max(initialHappiness - 15, 0));
    } else {
        citizen.respondToTax();
        CHECK(citizen.getHappinessMeter() == std::max(initialHappiness - 10, 0));
    }
}

TEST_CASE("Citizen respondToPayment increases happiness") {
    Citizen citizen;

    int initialHappiness = citizen.getHappinessMeter();
    citizen.respondToPayment();

    // Happiness should increase by 20 but not exceed 100
    CHECK(citizen.getHappinessMeter() == std::min(initialHappiness + 20, 100));
}
