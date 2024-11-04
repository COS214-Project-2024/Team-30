#include "Citizen.h"
#include "Building.h"
#include <iomanip>
int Citizen::nextID = 1;

//Just using the constructor and getID, those are the only important parts for my testing

Citizen::Citizen() : id(nextID++)
{
}

int Citizen::getID() const
{
    return id;
}
