#include "Steel.h"
#include <iostream>

Steel::Steel(int capacity)
    : Resource(capacity)
{
}

int Steel::getCapacity() const
{
    return capacity;  
}

void Steel::refill(int amount)
{
    capacity += amount;  
}

void Steel::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of steel. Remaining capacity: " << capacity << std::endl;
    } 
    else 
    {
        std::cout << "Not enough steel available to use " << amount << "." << std::endl;
    }
}


