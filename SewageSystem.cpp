#include "SewageSystem.h"
#include <iostream>

SewageSystem::SewageSystem()
    : working(true) // Initialize the sewage system as operational
{
}

void SewageSystem::setWorking(bool b) {
    working = b;
}

bool SewageSystem::getWorking() {
    return working;
}

int SewageSystem::manageDisposal(shared_ptr<Building> b) {
    if (!working) {
        std::cout << "Sewage system is not operational." << std::endl;
        return 0;
    }

    // Assume that the Building class has a method to manage sewage and returns an int (e.g., 100)
    int resetValue = 0; // Default reset value for sewage management
    std::cout << "Managing sewage disposal for building." << std::endl;

    // Logic to manage sewage disposal from the building would go here
    // For example, resetting the sewage level to a certain value
    b->setSewerage(resetValue); // Reset or adjust sewage level in the building

    std::cout << "Sewage disposal managed. Sewage level reset to " << resetValue << "." << std::endl;
    return resetValue;
}

void SewageSystem::manageTreatment() {
    if (working) {
        std::cout << "Managing sewage treatment..." << std::endl;
        // Implement treatment logic as necessary, e.g., purifying or filtering sewage
    } else {
        std::cout << "Sewage system is not operational. Cannot manage treatment." << std::endl;
    }
}

bool SewageSystem::repair() {
    if (!working) {
        working = true;
        std::cout << "Sewage system repaired and is now operational." << std::endl;
        return true;
    } else {
        std::cout << "Sewage system is already operational." << std::endl;
        return false;
    }
}

void SewageSystem::notifyCitizens(const string& message) {
    std::cout << "Notifying citizens: " << message << std::endl;
}
