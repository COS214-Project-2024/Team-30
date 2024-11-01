// #include <iostream>
// #include <memory>
// #include <vector>
// #include "Citizen.h"
// #include "EmploymentStatus.h"
// #include "Government.h"
// #include "ResidentialFactory.h"
// #include "CommercialFactory.h"
// #include "IndustrialFactory.h"
// #include "LandmarkFactory.h"
// #include "Fires.h"
// #include "Earthquake.h"
// #include "Building.h"
// #include "EmergencyServices.h"
// #include "Emergencies.h"

// // Function to test building assignment based on employment
// void testBuildingAssignment() {
//     std::cout << "=== Testing Building Assignment ===" << std::endl;

    // Set up factories and buildings
    ResidentialFactory residentialFactory;
    CommercialFactory commercialFactory;
    IndustrialFactory industrialFactory;

    auto residentialBuilding = std::shared_ptr<Building>(residentialFactory.createBuilding());
    auto commercialBuilding = std::shared_ptr<Building>(commercialFactory.createBuilding());
    auto industrialBuilding = std::shared_ptr<Building>(industrialFactory.createBuilding());

    // Set up citizens with different job statuses
    auto officeWorker = std::make_shared<Citizen>();
    auto factoryWorker = std::make_shared<Citizen>();
    auto unemployedPerson = std::make_shared<Citizen>();

    // Set employment statuses
    officeWorker->setEmploymentStatus(std::make_unique<OfficeJob>());
    factoryWorker->setEmploymentStatus(std::make_unique<IndustrialJob>());
    unemployedPerson->setEmploymentStatus(std::make_unique<Unemployed>());

    // Assign citizens to buildings based on employment
    officeWorker->assignToBuilding(commercialBuilding);
    factoryWorker->assignToBuilding(industrialBuilding);
    unemployedPerson->assignToBuilding(residentialBuilding);

    // Output to verify assignments
    commercialBuilding->displayInfo();
    industrialBuilding->displayInfo();
    residentialBuilding->displayInfo();
}

// Function to test emergency event and citizen happiness impact
void testEmergencyEventImpact() {
    std::cout << "\n=== Testing Emergency Event Impact on Citizens ===" << std::endl;

    // Create a residential building and add some citizens
    ResidentialFactory residentialFactory;
    auto residentialBuilding = std::shared_ptr<Building>(residentialFactory.createBuilding());

    auto citizen1 = std::make_shared<Citizen>();
    auto citizen2 = std::make_shared<Citizen>();

    citizen1->assignToBuilding(residentialBuilding);
    citizen2->assignToBuilding(residentialBuilding);
    
    citizen1->printDetails();
    citizen2->printDetails();

    // Trigger an emergency (fire) and check citizens' reactions
    Fires fireEvent;
    fireEvent.accessDamage(residentialBuilding);

    Earthquake earthquakeEvent;
    earthquakeEvent.accessDamage(residentialBuilding);

    // Display building and citizen info after the fire
    residentialBuilding->displayInfo();
    std::cout << "Citizen 1 happiness after fire: " << citizen1->getHappinessMeter() << std::endl;
    std::cout << "Citizen 2 happiness after fire: " << citizen2->getHappinessMeter() << std::endl;
}

// Function to test building capacity limits
void testBuildingCapacityLimits() {
    std::cout << "\n=== Testing Building Capacity Limits ===" << std::endl;

    // Create a residential building with limited capacity
    ResidentialFactory residentialFactory;
    auto residentialBuilding = std::shared_ptr<Building>(residentialFactory.createBuilding());
    residentialBuilding->setCapacity(2);  // Set a small capacity for testing

    auto citizen1 = std::make_shared<Citizen>();
    auto citizen2 = std::make_shared<Citizen>();
    auto citizen3 = std::make_shared<Citizen>();  // This one should exceed capacity

    citizen1->assignToBuilding(residentialBuilding);
    citizen2->assignToBuilding(residentialBuilding);
    citizen3->assignToBuilding(residentialBuilding);  // Should trigger capacity limit

    // Display building info to confirm capacity handling
    residentialBuilding->displayInfo();
}

// // Main function to run all tests
// int main() {
//     testBuildingAssignment();
//     testEmergencyEventImpact();
//     testBuildingCapacityLimits();
//     return 0;
// }
