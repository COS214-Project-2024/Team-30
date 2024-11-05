#include "Coal.h"
#include <iostream>

Coal::Coal(int capacity)
{
    this->capacity = capacity;
}

int Coal::getCapacity() const
{
    return capacity;  
}

void Coal::refill(int amount)
{
    capacity += amount;  
}

int Coal::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of coal. Remaining capacity: " << capacity << std::endl;
        return capacity;
    } 
    else 
    {
        std::cout << "Not enough coal available to use " << amount << "." << std::endl;
        return 0;
    }
}


