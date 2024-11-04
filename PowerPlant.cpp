#include "PowerPlant.h"
#include "Coal.h"

#include <iostream>

using namespace std;

PowerPlant::PowerPlant(Coal *c)
{
    working = true;
    coalResource = c;
    coalToDistribute = coalResource.use(10); // check if makes sense
    cout << "Power plant initialized.\n";
}

void PowerPlant::setWorking(bool w)
{
    working = w;
    cout << "Power Plant working status set to: " << working << endl;
}

bool PowerPlant::getWorking()
{
    return working;
}

void PowerPlant::setCoal(int i)
{
    coalToDistribute += coalResource.use(i);

    cout << "Coal supply level set to: " << coalToDistribute;
}

int PowerPlant::getCoal()
{
    return coalToDistribute;
}

int PowerPlant::generateElectricity(Building *b)
{
    coalToDistribute -= 10;

    if (working && coalToDistribute > 0)
    {
        cout << "Distributing power to building...\n";
        return 10;
    }
    else if (working && coalToDistribute < 0)
    {
        setWater(10);
        if (coalToDistribute >= 10)
        {
            distributeWater(b);
        } else {
            notifyCitizens('Notification: Power Plant Broken') ;
            setWorking(false);
            return 0;
        }
    }
    else
    {
        cout << "Power Plant not operational. Water distribution postponed.\n";
        return 0;
    }
}

bool PowerPlant::repair()
{
    setWorking(true);
    cout << "Power plant repaired and operational.\n";
    notifyCitizens('Notification: Power Plant Repaired');
    return working;
}

void PowerPlant::notifyCitizens(const string &message)
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