#include "WasteManagement.h"

#include <iostream>
#include <memory> // for shared_ptr

using namespace std;

WasteManagement::WasteManagement(){
    working = true;
    cout << "Waste management system initialized.\n";
}

void WasteManagement::setWorking(bool w){
    working = w;
    cout << "Waste Management working status set to: " << working << endl;
}

bool WasteManagement::getWorking()
{
    return working;
}

int WasteManagement::removeWaste(shared_ptr<Building> b){
    if (working) {
        cout << "Removing waste from building...\n";
        recycle();
        b->setWaste(100);
        return 100;
    } else {
        cout << "Waste management system not operational. Waste removal postponed.\n";
        return 0;
    }
}

void WasteManagement::recycle(){
        cout << "Recycling waste for building...\n";
}

bool WasteManagement::repair(){
    working = true;
    cout << "Waste Management system repaired and operational.\n";
    notifyCitizens("Notification: Waste Management Repaired");
    return working;
}

void WasteManagement::notifyCitizens(const string &message)
{
    cout << message << endl;;
}