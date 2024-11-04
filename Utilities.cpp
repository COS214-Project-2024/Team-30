#include "Utilities.h"
#include "Citizen.h"

#include <iostream>
#include <string>

using namespace std;

Utilities::Utilities(Building b)
{
    cout << "Providing city utilities to building...\n";

    powerPlant.generateElectricity();

    waterSupply.distributeWater();

    wasteManagement.removeWaste(Building b);
    wasteManagement.recycle(Building b);

    sewageSystem.manageDisposal(Building b);
    sewageSystem.manageTreatment(Building b);
}

void Utilities::notifyCitizens(const string &message)
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
        (*it)->update();
    }
}