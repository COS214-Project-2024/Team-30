#include "Buildings.h"

#include <iostream>

using namespace std;

// check if resources are available?
Utilities::Utilities(Building b){
    std::cout << "CityUtilitiesFacade: Providing city utilities...\n";
    powerPlant.generateElectricity();

    waterSupply.distributeWater();

    wasteManagement.removeWaste(Building b);
    wasteManagement.recycle(Building b);

    sewageSystem.manageDisposal(Building b);
    sewageSystem.manageTreatment(Building b);
}