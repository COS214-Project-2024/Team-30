#include "PowerPlant.h"
#include "Coal.h"

#include <iostream>

using namespace std;


PowerPlant::PowerPlant(Coal c){
    working = true;
    coalToDistribute = c.use(10); // check if makes sense
    cout << "Power plant initialized.\n";
}

void PowerPlant::setWorking(bool w){
    working = w;

    if (working)
        cout << "Power plant working status set to: TRUE";
    
    if (!working)
        cout << "Power plant working status set to: FALSE";
}

bool PowerPlant::getWorking()
{
    return working;
}

void PowerPlant::setCoal(Coal c, int i)
{
    coalToDistribute = c.use(i);

    cout << "Coal supply level set to: " << coalToDistribute;
}

int PowerPlant::getCoal()
{
    return coalToDistribute;
}

bool PowerPlant::generateElectricity(Building* b){
    if (working) {
        cout << "Generating electricity for building...\n";
    } else {
        cout << "Power plant not operational. No electricity generated.\n";
    }
}

bool PowerPlant::repair(){
    working = true;
    cout << "Power plant repaired and operational.\n";
    notifyCitizens('Notification: Power Plant Repaired')
    return working;
}

void PowerPlant::updateResourceLevel(bool b, int c)
{
    setWorking(b);
    setCoal(c);
    cout << "Updating coal resource level.\n";
    if (!b)
    {
        cout << "There is no water left to distribute" << endl;
    }
    else
    {
        cout << "Water level refiled for distribution" << endl;
    }
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

    cout << message << endl;;

    vector<Citizen *>::iterator it = residents.begin();
    for (it = residents.begin(); it != residents.end(); ++it)
    {
        (*it)->reactToUtilities(working);
    }
}