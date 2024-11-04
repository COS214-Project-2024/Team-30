#include "Concrete.h"
#include <iostream>

Concrete::Concrete(int capacity)
    : Resource(capacity)
{
}

int Concrete::getCapacity() const
{
    return capacity;  
}

void Concrete::refill(int amount)
{
    capacity += amount;  
}

int Concrete::use(int amount)
{
    if (amount <= capacity) {
        capacity -= amount;  
        std::cout << "Using " << amount << " of concrete. Remaining capacity: " << capacity << std::endl;
        return capacity;
    } 
    else 
    {
        std::cout << "Not enough concrete available to use " << amount << "." << std::endl;
        return 0;
    }
}


