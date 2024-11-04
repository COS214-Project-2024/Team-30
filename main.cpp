#include <iostream>
#include <memory>
#include "Government.h"
#include "Citizen.h"
#include "Fires.h"
#include "Earthquake.h"
#include "Building.h"
#include "EmergencyServices.h"
#include "Emergencies.h"
#include "Thieves.h"
#include "Government.h"
#include "PopulationCategorization.h"
#include "EconomyCategorization.h"
#include "Housing.h"
#include "Infrastructure.h"
#include "Economy.h"
#include "PopulationGrowth.h"
using namespace std;
// Function to display the main menu and capture user selection

unique_ptr<Government> cityGovernment;

// observers
Housing housingObserver;
Infrastructure infrastructureObserver;
Economy economyObserver;
PopulationGrowth populationObserver;

void addNewCitizen()
{
    cout << endl;
    cout << endl;
    cout << endl;
    std::shared_ptr<Citizen> newCitizen = std::make_shared<Citizen>();
    std::cout << "A new citizen has been added to the city!\n";
    cityGovernment->populationGrowth(newCitizen);
    cout << endl;
    cout << endl;
    cout << endl;
}

void CollectTaxes()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cityGovernment->collectTaxes();
    cout << "It's the 28th of Febuary and the Tax man is knocking!\n";
    cout << endl;
    cout << endl;
    cout << endl;
}

void IncreaseInfurstructure()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cityGovernment->increaseInfurstructure();
    cout << "Economy is growing time to expand\n";
    cout << endl;
    cout << endl;
    cout << endl;
}

void simulatePayDay()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "ITS PAY DAY!!\n";
    cityGovernment->payDay();
    cout << "Employed Citizens have been paid.\n";
    cout << endl;
    cout << endl;
    cout << endl;
}
void simulateJobOpportunites()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Government advises businesses to hire unemployed citizens\n";
    cityGovernment->jobOpportunities();
    cout << endl;
    cout << endl;
    cout << endl;
}
void RemoveSomeone()
{
    cout << "\n====== Remoeve Menu ======\n";
    cout << "Which Person would you like to remove\n";
    int choice;
    cin >> choice;

    cityGovernment->populationDecline(choice);
}

void SimulateDisaster()
{
    cout << "\n====== Disaster Menu ======\n";
    cout << "What disaster would you like \n";
    cout << "1) Fire\n";
    cout << "2) Earthquake \n";
    cout << "3) Thieves\n";
    int choice;
    cin >> choice;

    vector<std::shared_ptr<Building>> copyOfInfrastructure = cityGovernment->getInfrastructure();

    Fires fireEvent;
    Earthquake earthquakeEvent;
    Thieves thieveEvent;

    switch (choice)
    {
    case 1:
        for (const auto &building : copyOfInfrastructure)
        {
            if (building)
            {
                fireEvent.accessDamage(building);
            }
        }
        break;

    case 2:
        for (const auto &building : copyOfInfrastructure)
        {
            if (building)
            {
                earthquakeEvent.accessDamage(building);
            }
        }
        break;

    case 3:
        for (const auto &building : copyOfInfrastructure)
        {
            if (building)
            {
                thieveEvent.accessDamage(building);
            }
        }
        break;

    default:
        cout << "Invalid selection. Please try again.\n";
        break;
    }
}
void displayHeading()
{
    std::cout << "\033[32m"
              << R"(
  ______  __  .___________. __   _______     _______.        _______. __  .___  ___.  __    __   __          ___   .___________.  ______   .______      
 /      ||  | |           ||  | |   ____|   /       |       /       ||  | |   \/   | |  |  |  | |  |        /   \  |           | /  __  \  |   _  \     
|  ,----'|  | `---|  |----`|  | |  |__     |   (----`      |   (----`|  | |  \  /  | |  |  |  | |  |       /  ^  \ `---|  |----`|  |  |  | |  |_)  |    
|  |     |  |     |  |     |  | |   __|     \   \           \   \    |  | |  |\/|  | |  |  |  | |  |      /  /_\  \    |  |     |  |  |  | |      /     
|  `----.|  |     |  |     |  | |  |____.----)   |      .----)   |   |  | |  |  |  | |  `--'  | |  `----./  _____  \   |  |     |  `--'  | |  |\  \----.
 \______||__|     |__|     |__| |_______|_______/       |_______/    |__| |__|  |__|  \______/  |_______/__/     \__\  |__|      \______/  | _| `._____|
                                                                                                                                                        
)" << "\033[0m" // Reset color to default
              << std::endl;
}

void MassIntroduceCitizens()
{
    std::unique_ptr<CategorizationStrategy> popStrategy = std::make_unique<PopulationCategorization>();
    std::unique_ptr<CategorizationStrategy> ecoStrategy = std::make_unique<EconomyCategorization>();

    std::string val = "0";
    std::cout << "How many new citizens are entering the city? ";
    std::cin >> val;
    std::cout << std::endl;
    int numCitizens = stoi(val);

    for (int i = 0; i < numCitizens; i++)
    {
        auto citizen = std::make_shared<Citizen>();
        cityGovernment->populationGrowth(citizen);
    }
    cityGovernment->collectTaxes();
    cityGovernment->notifyObservers();

    std::cout << "\n------------------------------------------------------------------------------";
    std::cout << "\nCity categorization: " << std::endl;
    std::cout << "------------------------------------------------------------------------------\n";
    cityGovernment->setStrategy(popStrategy.get());
    std::cout << "City categorization by Population: " << cityGovernment->categorize() << std::endl;
    cityGovernment->setStrategy(ecoStrategy.get());
    std::cout << "City categorization by Economy: " << cityGovernment->categorize() << std::endl;
    std::cout << "------------------------------------------------------------------------------\n";
}
int displayMenu()
{
    cout << "\n====== Game Menu ======\n";
    cout << "1) Add to the population\n";
    cout << "2) Collect Taxes\n";
    cout << "3) Increase infrastructure\n";
    cout << "4) Simulate Disaster >:)!! \n";
    cout << "5) Move people around \n";
    cout << "6) Remove someone\n";
    cout << "7) Simulate a Pay Day\n";
    cout << "8) City Growth: Mass Increase Population\n";
    cout << "9) Print City Information\n";
    cout << "10) Print Citizens Summary\n";
    cout << "11) Create Job Opportunities\n"; // New option for job opportunities
    cout << "0) Exit Game\n";
    cout << "\nPlease make a selection: ";
    int choice;
    cin >> choice;
    return choice;
}

void handleMenuSelection(int choice)
{

    switch (choice)
    {
    case 0:
        cout << "Exiting game. Thank you for Playing!! Goodbye!!!!\n";
        break;
    case 1:
        addNewCitizen();
        break;
    case 2:
        CollectTaxes();
        break;
    case 3:
        IncreaseInfurstructure();
        break;
    case 4:
        SimulateDisaster();
        break;
    case 6:
        RemoveSomeone();
        break;
    case 7:
        simulatePayDay();
        break;
    case 8:
        MassIntroduceCitizens();
        break;
    case 9:
        cityGovernment->printInfo();
        break;
    case 10:
        cityGovernment->printCitizenSummary();
        break;
    case 11:
        simulateJobOpportunites();
        break;
    default:
        cout << "Invalid selection. Please try again.\n";
        break;
    }
}

void display_city_intro()
{

    std::cout << "    |-----|                            |-----|                             |-----|                            |-----|                         \n";
    std::cout << "    |     |                            |     |                             |     |                            |     |                         \n ";
    std::cout << "   |     |                            |     |                             |     |                            |     |                         \n";
    std::cout << "    |     |         /\\    /\\           |     |         /\\    /\\            |     |         /\\    /\\           |     |         /\\    /\\       \n";
    std::cout << "    |     |        /  \\__/  \\          |     |        /  \\__/  \\           |     |        /  \\__/  \\          |     |        /  \\__/  \\     \n";
    std::cout << "    |     |       /          \\         |     |       /          \\          |     |       /          \\         |     |       /          \\    \n";
    std::cout << "    |     |      |  _   _   _ |        |     |      |  _   _   _ |         |     |      |  _   _   _ |        |     |      |  _   _   _ |     \n";
    std::cout << "    |     |      | | | | | | ||        |     |      | | | | | | ||         |     |      | | | | | | ||        |     |      | | | | | | ||     \n";
    std::cout << "____|_____|_____ |_|_|_|_|_|_||    ____|_____|_____ |_|_|_|_|_|_||     ____|_____|_____ |_|_|_|_|_|_||    ____|_____|_____ |_|_|_|_|_|_||     \n";
}

int main()
{
    std::string cityName;
    display_city_intro();
    displayHeading();
    // Creative prompt for city name
    std::cout << "**Welcome to the City Simulator!**\n";
    std::cout << "Enter the name of your bustling metropolis: ";
    std::getline(std::cin, cityName);

    // Create the government object
    cityGovernment = std::make_unique<Government>(cityName);

    // info print(initial)
    cityGovernment->printInfo();

    cityGovernment->attach(&populationObserver);
    cityGovernment->attach(&housingObserver);
    cityGovernment->attach(&infrastructureObserver);
    cityGovernment->attach(&economyObserver);

    // Main game loop
    int choice;
    do
    {
        choice = displayMenu();
        handleMenuSelection(choice);
    } while (choice != 0);

    return 0;
}
