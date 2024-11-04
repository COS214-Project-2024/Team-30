#include "SewageSystem.h"

#include <iostream>

using namespace std;

SewageSystem::SewageSystem(){
    working = true;
    cout << "Sewage system initialized.\n";
}

void SewageSystem::setWorking(bool w){
    working = w;

    if (working)
        cout << "Sewage system working status set to: TRUE";
    
    if (!working)
        cout << "Sewage system working status set to: FALSE";
}

bool SewageSystem::getWorking()
{
    return working;
}

bool SewageSystem::manageDisposal(Building* b){
    if (working) {
        cout << "Managing sewage disposal for building...\n";
    } else {
        cout << "Sewage system not operational due to repairs needed. Disposal postponed.\n";
    }
}

bool SewageSystem::manageTreatment(Building* b){
    if (working) {
        cout << "Treating sewage for building...\n";
    } else {
        cout << "Sewage system not operational due to repairs needed. Treatment postponed.\n";
    }
}

bool SewageSystem::repair(){
    working = true;
    cout << "Sewage system repaired and operational.\n";
    notifyCitizens('Notification: Sewage System Repaired')
    return working;
}

void SewageSystem::notifyCitizens(const string &message)
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