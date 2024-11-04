#include "Wood.h"
#include <iostream>

Wood::Wood(int capacity)
    : Resource(capacity)
{
}

int Wood::getCapacity() const
{
    return capacity;  
}

void Wood::refill(int amount)
{
    capacity += amount;  
}

int Wood::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of wood. Remaining capacity: " << capacity << std::endl;
        return capacity;
    } 
    else 
    {
        std::cout << "Not enough wood available to use " << amount << "." << std::endl;
        return 0;
    }
}


