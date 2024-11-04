#include "SewageSystem.h"

#include <iostream>
#include <memory>

using namespace std;

SewageSystem::SewageSystem() {
    working = true;
    cout << "Sewage system initialized.\n";
}

void SewageSystem::setWorking(bool w) {
    working = w;
    cout << "Sewage System working status set to: " << (working ? "Operational" : "Non-operational") << endl;
}

bool SewageSystem::getWorking() {
    return working;
}

int SewageSystem::manageDisposal(shared_ptr<Building> b) {
    if (working) {
        cout << "Managing sewage disposal for building...\n";
        manageTreatment();
        b->setSewage(100);
        return 100;  // Returning a success code as described in the documentation
    } else {
        cout << "Sewage system not operational. Disposal postponed.\n";
        return 0;  // Return a failure or postponed status code
    }
}

void SewageSystem::manageTreatment() {
    cout << "Treating sewage for building...\n";
}

bool SewageSystem::repair() {
    working = true;
    cout << "Sewage system repaired and operational.\n";
    notifyCitizens("Notification: Sewage System Repaired");
    return working;
}

void SewageSystem::notifyCitizens(const string &message) {
    cout << message << endl;
}
