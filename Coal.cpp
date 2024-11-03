#include "Coal.h"
#include <iostream>

Coal::Coal(int capacity)
    : Resource(capacity)
{
}

int Coal::getCapacity() const
{
    return capacity;  
}

void Coal::refill(int amount)
{
    capacity += amount;  
}

void Coal::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of coal. Remaining capacity: " << capacity << std::endl;
    } 
    else 
    {
        std::cout << "Not enough coal available to use " << amount << "." << std::endl;
    }
}


