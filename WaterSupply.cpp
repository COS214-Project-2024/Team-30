#include "WaterSupply.h"
#include "Water.h"
#include "Building.h"
#include "Utilities.h"

#include <iostream>

using namespace std;

WaterSupply::WaterSupply(Water* w)
{
    working = true;
    waterToDistribute = w.use(10); // check if makes sense
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

bool WaterSupply::getWorking()
{
    return working;
}

void WaterSupply::setWater(int w)
{
    waterToDistribute = w;

    cout << "Water supply level set to: " << waterToDistribute;
}

int WaterSupply::getWater()
{
    return waterToDistribute;
}

bool WaterSupply::distributeWater(Building* b)
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
    notifyCitizens('Notification: Water Supply Repaired')
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




void WaterSupply::notifyCitizens(const string &message)
{
    // for (Citizen* citizen : citizens) {
    //     if (working) {
    //         citizen->increaseSatisfaction(10);  // increase satisfaction if working
    //     } else {
    //         citizen->decreaseSatisfaction(10);  // decrease satisfaction if not working
    //     }
    // }

    cout << message << endl;;

    vector<Citizen *>::iterator it = residents.begin();
    for (it = residents.begin(); it != residents.end(); ++it)
    {
        (*it)->reactToUtilities(working);
    }
}