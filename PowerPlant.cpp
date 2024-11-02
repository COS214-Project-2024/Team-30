#include "PowerPlant.h"

#include <iostream>

using namespace std;


PowerPlant::PowerPlant(){
    working = true;
    cout << "Power plant initialized.\n";
}

void PowerPlant::setWorking(bool w){
    working = w;

    if (working)
        cout << "Power plant working status set to: TRUE";
    
    if (!working)
        cout << "Power plant working status set to: FALSE";
}

bool PowerPlant::generateElectricity(Building b){
    if (working) {
        cout << "Generating electricity for building...\n";
    } else {
        cout << "Power plant not operational. No electricity generated.\n";
    }
}

bool PowerPlant::repair(){
    working = true;
    cout << "Power plant repaired and operational.\n";
    return working;
}

void PowerPlant::updateResourceLevel(){
    cout << "Updating coal resource level for power plant.\n";
}