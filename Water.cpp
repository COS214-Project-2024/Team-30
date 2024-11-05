#include "Water.h"
#include <iostream>

Water::Water(int capacity)
{
    this->capacity = capacity;
}

int Water::getCapacity() const
{
    return capacity;  
}

void Water::refill(int amount)
{
    capacity += amount;  
}

int Water::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of water. Remaining capacity: " << capacity << std::endl;
        return capacity;
    } 
    else 
    {
        std::cout << "Not enough water available to use " << amount << "." << std::endl;
        return 0;
    }
}


