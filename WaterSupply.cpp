#include "WaterSupply.h"
#include "Water.h"
#include "Building.h"

#include <iostream>
#include <memory>

using namespace std;

WaterSupply::WaterSupply(shared_ptr<Water> w) {
    working = true;
    waterResource = w;
    cout << "Water supply system initialized.\n";
}

void WaterSupply::setWorking(bool w) {
    working = w;
    cout << "Water supply working status set to: " << working << endl;
}

bool WaterSupply::getWorking() {
    return working;
}

void WaterSupply::setWater(int w) {
    waterToDistribute = w;
    cout << "Water supply level set to: " << waterToDistribute << endl;
}

int WaterSupply::getWater() {
    return waterToDistribute;
}

int WaterSupply::distributeWater(shared_ptr<Building> b) {
    if (!working) {
        std::cout << "Water supply system is not operational." << std::endl;
        return 0;
    }

    if (waterToDistribute <= 0) {
        std::cout << "No water available to distribute." << std::endl;
        return 0;
    }

    int waterUsed = waterResource->use(waterToDistribute);
    if (waterUsed > 0) {
        std::cout << "Distributed " << waterUsed << " units of water to the building." << std::endl;
        b->receiveWater(waterUsed);
        waterToDistribute -= waterUsed;
    } else {
        std::cout << "Unable to distribute water; not enough in resource." << std::endl;
    }
    return waterUsed;
}

bool WaterSupply::repair() {
    setWorking(true);
    cout << "Water supply repaired and operational.\n";
    notifyCitizens("Notification: Water Supply Repaired");
    return working;
}

void WaterSupply::notifyCitizens(const string& message) {
    cout << message << endl;
}
