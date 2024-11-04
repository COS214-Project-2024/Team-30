#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(shared_ptr<Coal> c)
    : coalResource(c), working(true), coalToDistribute(0)
{
}

void PowerPlant::setWorking(bool b) {
    working = b;
}

bool PowerPlant::getWorking() {
    return working;
}

void PowerPlant::setCoal(int w) {
    coalToDistribute = w;
}

int PowerPlant::getCoal() {
    return coalToDistribute;
}

int PowerPlant::generateElectricity(shared_ptr<Building> b) {
    if (!working) {
        std::cout << "Power plant is not operational." << std::endl;
        return 0;
    }

    if (coalToDistribute <= 0) {
        std::cout << "No coal available to generate electricity." << std::endl;
        return 0;
    }

    // Attempt to use the coal to generate electricity
    int coalUsed = coalResource->use(coalToDistribute);
    if (coalUsed > 0) {
        std::cout << "Generated electricity using " << coalUsed << " units of coal." << std::endl;
        b->receiveElectricity(coalUsed);  // Assume Building has a receiveElectricity method
        coalToDistribute -= coalUsed;
    } else {
        std::cout << "Unable to generate electricity; not enough coal." << std::endl;
    }
    return coalUsed;
}

bool PowerPlant::repair() {
    if (!working) {
        working = true;
        std::cout << "Power plant repaired and is now operational." << std::endl;
        return true;
    } else {
        std::cout << "Power plant is already operational." << std::endl;
        return false;
    }
}

void PowerPlant::notifyCitizens(const string& message) {
    std::cout << "Notifying citizens: " << message << std::endl;
}
