#include "WaterSupply.h"

#include <iostream>

using namespace std;

WaterSupply::WaterSupply(){
    working = true;
    cout << "Water supply system initialized.\n";
}

void WaterSupply::setWorking(bool w){
    working = w;

    if (working)
        cout << "Water supply working status set to: TRUE";
    
    if (!working)
        cout << "Water supply working status set to: FALSE";
}

bool WaterSupply::distributeWater(Building b){
    if (working) {
        cout << "Distributing water to building...\n";
    } else {
        cout << "Water supply system not operational. Water distribution postponed.\n";
    }
}

bool WaterSupply::repair(){
    working = true;
    cout << "Water supply repaired and operational.\n";
    return working;
}

void WaterSupply::updateResourceLevel(){
    cout << "Updating water resource level.\n";
}