#include "Building.h"

Building::Building(int capacity,string name): capacity(capacity), name(name){}

void Building::addCitizen(shared_ptr<Citizen> citizen) {
    if (residents.size() < capacity) {
        residents.push_back(citizen);
    } else {
        cout << "Building is at full capacity!" << endl;
    }
}

void Building::removeCitizen(shared_ptr<Citizen> citizen) {
    if (this->containsCitizen(citizen));
    residents.erase(remove(residents.begin(), residents.end(), citizen), residents.end());
}

bool Building::containsCitizen(shared_ptr<Citizen> citizen)
{
    auto it = find(residents.begin(),residents.end(),citizen);
    if (it == residents.end())
    {

        return false;
    }
    return true;
}

void Building::printResidents()
{
    if (residents.empty()) {
        cout << "No residents in the building." << endl;
        return;
    }
    cout << "Residents' ID numbers:\n";
    for (const auto& resident : residents) {
        if (resident) {
            cout << resident->getID() << "\n";
        }
    }
    cout << endl;

}

string Building::getName()
{
    return name;
}