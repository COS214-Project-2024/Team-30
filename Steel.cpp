#include "Steel.h"
#include <iostream>

Steel::Steel(int capacity)
    
{
    this->capacity = capacity;
}

int Steel::getCapacity() const
{
    return capacity;  
}

void Steel::refill(int amount)
{
    capacity += amount;  
}

int Steel::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of steel. Remaining capacity: " << capacity << std::endl;
        return capacity;
    } 
    else 
    {
        std::cout << "Not enough steel available to use " << amount << "." << std::endl;
        return 0;
    }
}


