#include "WaterSupply.h"
#include "Water.h"
#include "Building.h"

#include <iostream>
#include <memory>

using namespace std;

WaterSupply::WaterSupply(shared_ptr<Water> w) {
    working = true;
    waterResource = w;
    waterToDistribute = waterResource->use(100); // Assumes Water has a use method returning int
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
    waterToDistribute += waterResource->use(w);
    cout << "Water supply level set to: " << waterToDistribute << endl;
}

int WaterSupply::getWater() {
    return waterToDistribute;
}

int WaterSupply::distributeWater(shared_ptr<Building> b) {
    waterToDistribute -= 100;

    if (working && waterToDistribute > 0) {
        cout << "Distributing water to building...\n";
        return 100;
    } else if (working && waterToDistribute < 0) {
        setWater(100);
        if (waterToDistribute >= 100) {
            return distributeWater(b);
        } else {
            notifyCitizens("Notification: Water Supply Broken");
            setWorking(false);
            return 0;
        }
    } else {
        cout << "Water supply system not operational. Water distribution postponed.\n";
        return 0;
    }
}

bool WaterSupply::repair() {
    setWorking(true);
    cout << "Water supply repaired and operational.\n";
    notifyCitizens("Notification: Water Supply Repaired");
    return working;
}

void WaterSupply::notifyCitizens(const string& message) {
    cout << message << endl;

    for (const auto& resident : residents) {
        resident->reactToUtilities(working); // Assuming `reactToUtilities` is a method in Citizen
    }
}
