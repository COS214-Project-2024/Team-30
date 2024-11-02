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
using namespace std;
// Function to display the main menu and capture user selection

unique_ptr<Government> cityGovernment;

void addNewCitizen() {
    cout<< endl;
    cout<< endl;
    cout<< endl;
    std::shared_ptr<Citizen> newCitizen = std::make_shared<Citizen>();
    std::cout << "A new citizen has been added to the city!\n";
    cityGovernment->populationGrowth(newCitizen);
    cout<< endl;
    cout<< endl;
    cout<< endl;
}

void CollectTaxes() {
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cityGovernment->collectTaxes();
    cout << "It's the 28th of Febuary and the Tax man is knocking!\n";
    cout<< endl;
    cout<< endl;
    cout<< endl;
}

void IncreaseInfurstructure() {
    cout<< endl;
    cout<< endl;
    cout<< endl;
    cityGovernment->increaseInfurstructure();
    cout << "Economy is growing time to expand\n";
    cout<< endl;
    cout<< endl;
    cout<< endl;
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

    switch (choice) {
        case 1:
             for (const auto &building : copyOfInfrastructure) 
             {
                if (building)
                {fireEvent.accessDamage(building);}
            }
            break;
        
        
        case 2:
            for (const auto &building : copyOfInfrastructure) 
             {
                if (building)
                {earthquakeEvent.accessDamage(building);}
            }
            break;
        
        
        case 3:
            for (const auto &building : copyOfInfrastructure) 
             {
                if (building)
                {thieveEvent.accessDamage(building);}
            }
            break;
       
       
        default:
            cout << "Invalid selection. Please try again.\n";
            break;


    }
  


}

int displayMenu() {

    cityGovernment->printInfo();
    cout << "\n====== Game Menu ======\n";
    cout << "1) Add to the population\n";
    cout << "2) Collect Taxes\n";
    cout << "3) Increase infrastructure\n";
    cout << "4) Simulate Disaster >:)!! \n";
    cout << "5) Move people around \n";
    cout << "6) Kill someone\n";
    cout << "7) Change someones job\n";
    std::cout<<"8) City Growth:Mass Increase population\n ";
    cout << "0) Exit Game\n";
    int choice;
    cin >> choice;
    return choice;


}

void MassIntroduceCitizens(){

}


void handleMenuSelection(int choice) {
    switch (choice) {
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
        case 8:
            MassIntroduceCitizens();
        default:
            cout << "Invalid selection. Please try again.\n";
            break;
    }
}

int main() {
    std::string cityName;

    // Creative prompt for city name
    std::cout << "**Welcome to the City Simulator!**\n";
    std::cout << "Enter the name of your bustling metropolis: ";
    std::getline(std::cin, cityName);

    // Create the government object
    cityGovernment =std::make_unique<Government>(cityName);

    // Main game loop
    int choice;
    do {
        choice = displayMenu();
        handleMenuSelection(choice);
    } while (choice != 0);

    return 0;
}


