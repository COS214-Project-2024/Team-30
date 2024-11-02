#include "WasteManagement.h"

#include <iostream>

using namespace std;

WasteManagement::WasteManagement(){
    working = true;
    cout << "Waste management system initialized.\n";
}

void WasteManagement::setWorking(bool w){
    working = w;

    if (working)
        cout << "Waste Management system working status set to: TRUE";
    
    if (!working)
        cout << "Waste Management system working status set to: FALSE";
}

bool WasteManagement::removeWaste(Building b){
    if (working) {
        cout << "Removing waste from building...\n";
    } else {
        cout << "Waste management system not operational. Waste removal postponed.\n";
    }
}

bool WasteManagement::recycle(Building b){
    if (working) {
        cout << "Recycling waste for building...\n";
    } else {
        cout << "Waste management system not operational. Recycling postponed.\n";
    }
}

bool WasteManagement::repair(){
    working = true;
    cout << "Waste Management system repaired and operational.\n";
    return working;
}