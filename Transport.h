#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <list>
#include "Citizens.h"
#include "Building.h"

using namespace std;

class Transport {
protected:
    list<Citizens> passengers;
    int capacity;
    string name;
public:
    Transport(string name, int capacity);
    virtual ~Transport() = default;//default destructor
    void addPeople(const list<Citizens>& people);
    void removePeople(const list<Citizens>& people);
    virtual void move(Building from, Building to) = 0;
};

#endif

