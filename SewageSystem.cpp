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

bool SewageSystem::manageDisposal(Building b){
    if (working) {
        cout << "Managing sewage disposal for building...\n";
    } else {
        cout << "Sewage system not operational due to repairs needed. Disposal postponed.\n";
    }
}

bool SewageSystem::manageTreatment(Building b){
    if (working) {
        cout << "Treating sewage for building...\n";
    } else {
        cout << "Sewage system not operational due to repairs needed. Treatment postponed.\n";
    }
}

bool SewageSystem::repair(){
    working = true;
    cout << "Sewage system repaired and operational.\n";
    return working;
}