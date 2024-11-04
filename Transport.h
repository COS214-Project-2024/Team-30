#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <vector>
#include <memory>
#include "Citizen.h"
#include "Building.h"
#include <algorithm>

using namespace std;

class Building;

class Transport {
protected:
    vector<shared_ptr<Citizen>> passengers;
    int capacity;
    string name;
    shared_ptr<Building> from;

public:
    Transport(string name, int capacity, shared_ptr<Building> from);
    virtual ~Transport() = default; // default destructor
    void addPeople(shared_ptr<Citizen> c); //this was why i needed the unique pointers
    void removePeople(shared_ptr<Citizen> c);
    virtual void Travel(shared_ptr<Building> to) = 0;
    void removeAllPeople();
    void printPassengers();
};

#endif // TRANSPORT_H


