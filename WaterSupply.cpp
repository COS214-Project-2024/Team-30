#include "WaterSupply.h"
#include "Water.h"
#include "Building.h"
#include "Utilities.h"

#include <iostream>

using namespace std;

WaterSupply::WaterSupply(Water *w)
{
    working = true;
    waterToDistribute = w.use(10); // check if makes sense
    cout << "Water supply system initialized.\n";
}

void WaterSupply::setWorking(bool w)
{
    working = w;
    cout << "Water supply working status set to: " << working << endl;
}

bool WaterSupply::getWorking()
{
    return working;
}

void WaterSupply::setWater(int w)
{
    waterToDistribute += w.use(w);

    cout << "Water supply level set to: " << waterToDistribute;
}

int WaterSupply::getWater()
{
    return waterToDistribute;
}

int WaterSupply::distributeWater(Building *b, int n)
{
    waterToDistribute -= n;

    if (working && waterToDistribute > 0)
    {
        cout << "Distributing water to building...\n";
        return n;
    }
    else if (working && waterToDistribute < 0)
    {
        setWater(n);
        if (waterToDistribute >= n)
        {
            distributeWater(b, n);
        } else {
            return 0;
        }
    }
    else
    {
        cout << "Water supply system not operational. Water distribution postponed.\n";
        return 0;
    }
}

bool WaterSupply::repair()
{
    setWorking(true);
    cout << "Water supply repaired and operational.\n";
    notifyCitizens('Notification: Water Supply Repaired') 
    return working;
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

    cout << message << endl;
    ;

    vector<Citizen *>::iterator it = residents.begin();
    for (it = residents.begin(); it != residents.end(); ++it)
    {
        (*it)->reactToUtilities(working);
    }
}