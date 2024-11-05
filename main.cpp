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
#include "BillboardSign.h"
#include "Roadsign.h"
#include "PrivateTransport.h"
#include "Plane.h"
#include "Taxi.h"
#include "Train.h"
#include "SetRedLightsCommand.h"
#include "TrafficCommand.h"

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


void TestTravelling()
{
    ResidentialFactory residentialFactory;
    shared_ptr<Building> b1 = residentialFactory.createBuilding();
    shared_ptr<Building> b2 = residentialFactory.createBuilding();
    shared_ptr<Building> b3 = residentialFactory.createBuilding();

    //citizens:
    shared_ptr<Citizen> c1 = make_shared<Citizen>();
    shared_ptr<Citizen> c2 = make_shared<Citizen>();
    shared_ptr<Citizen> c3 = make_shared<Citizen>();
    shared_ptr<Citizen> c4 = make_shared<Citizen>();
    shared_ptr<Citizen> c5 = make_shared<Citizen>();
    shared_ptr<Citizen> c6 = make_shared<Citizen>();
    shared_ptr<Citizen> c7 = make_shared<Citizen>();
    shared_ptr<Citizen> c8 = make_shared<Citizen>();
    shared_ptr<Citizen> c9 = make_shared<Citizen>();
    shared_ptr<Citizen> c10 = make_shared<Citizen>();
    shared_ptr<Citizen> c11 = make_shared<Citizen>();
    //signs:
    Sign mySign("Hey look at me! Im a sign");
    //BillboardSigns
    BillboardSign myBill("this is a billboard"); //what if as we traverse we print the messages for wgat we see in the billboards?
    BillboardSign myBill2("Come on over to Krispy Kreme!");
    BillboardSign myBill3("Be sure to drive safely!");
    BillboardSign mybill4("Come watch the rugby with us at Pirates rugby club!");
    //Roadsigns
    RoadSign stopSign("STOP");
    RoadSign yield("Yield");
    RoadSign school("Drive slowly in the school areas!\n");

    //commands
    shared_ptr<trafficCommand> cmd;
    //Planes
    shared_ptr<Plane> myPlane = make_shared<Plane>(5,b1);
    //PrivateTransport
    shared_ptr<privateTransport> myPrivate = make_shared<privateTransport>(5,b1);
    //Taxi
    shared_ptr<Taxi> myTaxi = make_shared<Taxi>(5,b1);
  
    //Roads
    shared_ptr<Road> r1 = make_shared<Road>();
    shared_ptr<Road> r2 = make_shared<Road>();
    shared_ptr<Road> r3 = make_shared<Road>();
    shared_ptr<Road> r4 = make_shared<Road>();
    //Area
    shared_ptr<Area> a1 = make_shared<Area>("Generic area 7even");
    r1->addSign(mySign);
    r1->addSign(myBill);
    r1->addSign(myBill2);
    r2->addSign(yield);
    r2->addSign(myBill2);
    r3->addSign(myBill3);
    r3->addSign(mybill4);


    b1->addCitizen(c1);
    b1->addCitizen(c2);
    b1->addCitizen(c3);
    b1->addCitizen(c4);
    b1->addCitizen(c5);

    r1->addBuilding(b1);
    r2->addBuilding(b2);
    r3->addBuilding(b3);   

    a1->addRoad(r1);
    a1->addRoad(r2);
    a1->addRoad(r3);
    a1->addRoad(r4);

    r1->addSign(mySign);
    r2->addSign(myBill);
    r2->addSign(myBill2);

    cout << "Residents before loading the plane:\n";
    b1->printResidents();
    myPlane->addPeople(c1);
    cout << "Residents after loading the plane:\n";
    b1->printResidents();
    cout << "Building 2 before travel:\n";
    b2->printResidents();
    myPlane->Travel(b2);
    cout << "Building 2 after travel:\n";
    b2->printResidents();

    cout << "The private vehicle is now going to take passengers from b1 to b3\n";
    cout << "Building before loading the car with citizen 3:\n";
    b1->printResidents();
    myPrivate->addPeople(c3);
    b1->printResidents();
    cout << "b3 residents before travel:\n";
    b3->printResidents();
    cout << "Building 3 is on road: ";
    cout << b3->getRoad()->getID() << endl;
    cout << "Road 3 ID: " << r3->getID() << endl;
    myPrivate->Travel(b3);
    cout << "Lets look at the updated b3 residents!!:\n";
    b3->printResidents();


    shared_ptr<trafficCommand> redLightsCmd = make_shared<SetRedLightsCommand>(a1);
    shared_ptr<Train> myTrain = make_shared<Train>(5, b1, redLightsCmd);

    //trafficLights:
    unique_ptr<TrafficLight> t1 = make_unique<TrafficLight>();
    unique_ptr<TrafficLight> t2 = make_unique<TrafficLight>();
    unique_ptr<TrafficLight> t3 = make_unique<TrafficLight>();

    t1->changeState();
    t2->changeState();
    r1->addLight(move(t1));
    r2->addLight(move(t2));
    r2->addLight(move(t1));

    b1->addCitizen(c1);
    b1->addCitizen(c2);

    cout << "Building 1 residents before train travel:\n";
    b1->printResidents();
    myTrain->addPeople(c4);
    cout << "Building 1 residents after loading the train:\'n";
    b1->printResidents();

    cout << "Train is travelling to Building 2...\n";
    myTrain->Travel(b2);

    cout << "Building 2 residents after train travel:\n";
    b2->printResidents();



}


int displayMenu()
{
    cout << "\n         ====== Simulation Menu ======\n";
    cout << "           1) Add to the population\n";
    cout << "           2) Collect Taxes\n";
    cout << "           3) Increase infrastructure\n";
    cout << "           4) Simulate Disaster >:)!! \n";
    cout << "           5) Move people around \n";
    cout << "           6) Remove someone\n";
    cout << "           7) Simulate a Pay Day\n";
    cout << "           8) City Growth: Mass Increase Population\n";
    cout << "           9) Print City Information\n";
    cout << "           10) Print Citizens Summary\n";
    cout << "           11) Create Job Opportunities\n"; // New option for job opportunities
    cout << "           0) Exit Game\n";
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
    case 5:
        TestTravelling();
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

