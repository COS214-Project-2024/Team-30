#include <iostream>
#include "Transport.h"

using namespace std;

Transport::Transport(string name, int capacity, shared_ptr<Building> from)
        : name(move(name)), capacity(capacity), from(move(from)) {}

void Transport::addPeople(shared_ptr<Citizen> c) {
    if (from->containsCitizen(c)) { //if i did remove the citizen
        auto it = std::find(passengers.begin(), passengers.end(), c);
        if (it == passengers.end())//if the passenger isnt in the vehivle
        {
            if (passengers.size() < capacity) {
                passengers.push_back(c);
                cout << "Passenger " << c->getID() << " added successfully." << endl;
                from->removeCitizen(c);
            } else {
                cout << "Transport is at full capacity. Cannot add more passengers." << endl;
            }
        } else {
            cout << "Passenger is already in the transport." << endl;
        }
    }
}


void Transport::removePeople(shared_ptr<Citizen> c) {
    if (passengers.empty())
    {
        cout << "Transport is empty" << endl;
        return;
    }
    auto it = find(passengers.begin(), passengers.end(), c);
    if (it != passengers.end()) {
        passengers.erase(it);
        from->addCitizen(move(c));
    } else {
        cout << "Passenger not found in the transport." << endl;
    }
}

void Transport::removeAllPeople()
{
    while (!passengers.empty()) {
        from->addCitizen(passengers.back());
        passengers.pop_back();
    }
}

void Transport::printPassengers()
{
    if (passengers.empty()) {
        cout << "No passengers in the vehicle." << endl;
        return;
    }
    cout << "Passengers' ID numbers:\n";
    for (const auto& passenger : passengers) {
        if (passenger) {
            cout << passenger->getID() << "\n";
        }
    }
    cout << endl;
}