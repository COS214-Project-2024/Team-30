#include "PowerPlant.h"
#include "Coal.h"

#include <iostream>
#include <memory>

using namespace std;

PowerPlant::PowerPlant(shared_ptr<Coal> c)
{
    working = true;
    coalResource = c;
    coalToDistribute = coalResource->use(100); // Assumes 'use' deducts coal and returns amount used
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
    int usedCoal = coalResource->use(i); // Deduct coal from the resource
    coalToDistribute += usedCoal;
    cout << "Coal supply level set to: " << coalToDistribute << endl;
}

int PowerPlant::getCoal()
{
    return coalToDistribute;
}

int PowerPlant::generateElectricity(shared_ptr<Building> b)
{
    if (working)
    {
        if (coalToDistribute >= 100) // Check if there's enough coal
        {
            coalToDistribute -= 100; // Deduct coal for electricity generation
            cout << "Distributing power to building...\n";
            return 100; // Return amount of electricity generated
        }
        else
        {
            notifyCitizens("Notification: Not enough coal for electricity generation.");
            setWorking(false); // Power plant goes offline due to lack of resources
            return 0;
        }
    }
    else
    {
        cout << "Power Plant not operational. Power distribution postponed.\n";
        return 0;
    }
}

bool PowerPlant::repair()
{
    setWorking(true);
    cout << "Power plant repaired and operational.\n";
    notifyCitizens("Notification: Power Plant Repaired");
    return working;
}

void PowerPlant::notifyCitizens(const string &message)
{
    cout << message << endl;
}