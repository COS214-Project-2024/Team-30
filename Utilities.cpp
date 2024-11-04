#include "Utilities.h"
#include "Building.h"
#include "Coal.h"
#include "Water.h"

#include <iostream>
#include <string>
#include <memory>

using namespace std;

Utilities::Utilities(Building* b, Coal* c, Water* w) {
    cout << "Providing city utilities to building...\n";

    powerPlant = std::make_unique<PowerPlant>(c);
    waterSupply = std::make_unique<WaterSupply>(w);
    wasteManagement = std::make_unique<WasteManagement>();
    sewageSystem = std::make_unique<SewageSystem>();

    b->setPower(powerPlant->generateElectricity(b));
    b->setWater(waterSupply->distributeWater(b));
    b->setWaste(wasteManagement->removeWaste(b));
    b->setSewage(sewageSystem->manageDisposal(b));

    working = (powerPlant->getWorking() &&
               waterSupply->getWorking() &&
               wasteManagement->getWorking() &&
               sewageSystem->getWorking());
}
