#include "Utilities.h"
#include "Citizen.h"

#include <iostream>
#include <string>

using namespace std;

Utilities::Utilities(Building* b)
{
    cout << "Providing city utilities to building...\n";

    powerPlant = new PowerPlant();
    waterSupply = new WaterSupply();
    wasteManagement = new WasteManagement();
    sewageSystem = new SewageSystem();

    powerPlant.generateElectricity(b);

    waterSupply.distributeWater(b);

    wasteManagement.removeWaste(b);
    wasteManagement.recycle(b);

    sewageSystem.manageDisposal(b);
    sewageSystem.manageTreatment(b);

    if (
        powerPlant.getWorking() &&
        waterSupply.getWorking() &&
        wasteManagement.getWorking() &&
        sewageSystem.getWorking()
    ){
        working = true;
    }
    else{
        working = false;
    }
}