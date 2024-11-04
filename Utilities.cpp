#include "Utilities.h"
#include "Building.h"
#include "Coal.h"
#include "Water.h"

#include <iostream>
#include <string>

using namespace std;

Utilities::Utilities(Building* b, Coal*c, Water* w)
{
    cout << "Providing city utilities to building...\n";

    powerPlant = new PowerPlant(c);
    waterSupply = new WaterSupply(w);
    wasteManagement = new WasteManagement();
    sewageSystem = new SewageSystem();

    b->power = powerPlant.generateElectricity(b);

    b->water = waterSupply.distributeWater(b);

    b->waste = wasteManagement.removeWaste(b);

    b->sewage = sewageSystem.manageDisposal(b);

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