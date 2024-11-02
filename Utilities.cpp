#include "Utilities.h"

#include <iostream>
#include <string>

using namespace std;

Utilities::Utilities(Building b){
    cout << "Providing city utilities to building...\n";
    
    powerPlant.generateElectricity();

    waterSupply.distributeWater();

    wasteManagement.removeWaste(Building b);
    wasteManagement.recycle(Building b);

    sewageSystem.manageDisposal(Building b);
    sewageSystem.manageTreatment(Building b);
}

void Utilities::notifyCitizens(const string& message) {
    cout << "Notification to citizens: " << message << endl;
}