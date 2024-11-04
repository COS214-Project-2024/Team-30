#include "WaterSupply.h"
#include "Water.h"

#include <iostream>

using namespace std;

WaterSupply::WaterSupply()
{
    working = true;
    cout << "Water supply system initialized.\n";
}

void WaterSupply::setWorking(bool w)
{
    working = w;

    if (working)
        cout << "Water supply working status set to: TRUE";

    if (!working)
        cout << "Water supply working status set to: FALSE";
}

void WaterSupply::setWater(int w)
{
    waterToDistribute = w;

    cout << "Water supply level set to: " << waterToDistribute;
}

bool WaterSupply::distributeWater(Building b)
{
    if (working)
    {
        cout << "Distributing water to building...\n";
    }
    else
    {
        cout << "Water supply system not operational. Water distribution postponed.\n";
    }
}

bool WaterSupply::repair()
{
    working = true;
    cout << "Water supply repaired and operational.\n";
    return working;
}

void WaterSupply::updateResourceLevel(bool b, int c)
{
    setWorking(b);
    setWater(c);
    cout << "Updating water resource level.\n";
    if (!b)
    {
        cout << "There is no water left to distribute" << endl;
    }
    else
    {

        cout << "Water level refiled for distribution" << endl;
    }
}