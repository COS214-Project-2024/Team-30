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

    b.power = powerPlant.generateElectricity(b);

    b.water = waterSupply.distributeWater(b);

    b.waste = wasteManagement.removeWaste(b);

    b.sewage = sewageSystem.manageDisposal(b);

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