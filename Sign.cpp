#include "Sign.h"
#include <iostream>
using namespace std;

int Sign::numSigns = 0;

Sign::Sign(const string& message) : message(message), ID(++numSigns)
{
    this->type = "Generic sign";
}

int Sign::getID() const
{
    return  ID;
}

string Sign::getMessage() const
{
    return message;
}

string Sign::getType() const
{
    return type;
}
