#include "Water.h"
#include <iostream>

Water::Water(int capacity)
    : Resource(capacity)
{
}

int Water::getCapacity() const
{
    return capacity;  
}

void Water::refill(int amount)
{
    capacity += amount;  
}

void Water::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of water. Remaining capacity: " << capacity << std::endl;
    } 
    else 
    {
        std::cout << "Not enough water available to use " << amount << "." << std::endl;
    }
}


