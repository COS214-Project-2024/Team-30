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

bool WasteManagement::getWorking()
{
    return working;
}

bool WasteManagement::removeWaste(Building* b){
    if (working) {
        cout << "Removing waste from building...\n";
    } else {
        cout << "Waste management system not operational. Waste removal postponed.\n";
    }
}

bool WasteManagement::recycle(Building* b){
    if (working) {
        cout << "Recycling waste for building...\n";
    } else {
        cout << "Waste management system not operational. Recycling postponed.\n";
    }
}

bool WasteManagement::repair(){
    working = true;
    cout << "Waste Management system repaired and operational.\n";
    notifyCitizens('Notification: Waste Management Repaired')
    return working;
}

void WasteManagement::notifyCitizens(const string &message)
{
    // for (Citizen* citizen : citizens) {
    //     if (working) {
    //         citizen->increaseSatisfaction(10);  // increase satisfaction if working
    //     } else {
    //         citizen->decreaseSatisfaction(10);  // decrease satisfaction if not working
    //     }
    // }

    cout << message << endl;;

    vector<Citizen *>::iterator it = residents.begin();
    for (it = residents.begin(); it != residents.end(); ++it)
    {
        (*it)->reactToUtilities(working);
    }
}