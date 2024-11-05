#include "WasteManagement.h"
#include <iostream>

WasteManagement::WasteManagement()
    : working(true) // Initialize the waste management system as operational
{
}

void WasteManagement::setWorking(bool b)
{
    working = b;
}

bool WasteManagement::getWorking()
{
    return working;
}

int WasteManagement::removeWaste(shared_ptr<Building> b)
{
    if (!working)
    {
        std::cout << "Waste management system is not operational." << std::endl;
        return 0;
    }

    // Assume that the Building class has a method to get and remove waste
    int wasteAmount = b->getWaste(); // Retrieve current waste amount
    if (wasteAmount > 0)
    {
        // Assume Building has a method to reset waste or reduce it
        b->setWaste(0); // Remove all waste for simplicity, or set to a lower amount
        std::cout << "Removed " << wasteAmount << " units of waste from the building." << std::endl;
        return wasteAmount;
    }
    else
    {
        std::cout << "No waste to remove from the building." << std::endl;
        return 0;
    }
}

void WasteManagement::recycle()
{
    if (working)
    {
        std::cout << "Recycling waste..." << std::endl;
        // Implement recycling logic as necessary, this could be an elaborate operation
    }
    else
    {
        std::cout << "Waste management system is not operational. Cannot recycle." << std::endl;
    }
}

bool WasteManagement::repair()
{
    if (!working)
    {
        working = true;
        std::cout << "Waste management system repaired and is now operational." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Waste management system is already operational." << std::endl;
        return false;
    }
}

void WasteManagement::notifyCitizens(const string &message)
{
    std::cout << "Notifying citizens: " << message << std::endl;
}
