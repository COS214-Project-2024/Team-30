#ifndef AREA_H
#define AREA_H

#include <string>
#include <list>
#include "Road.h"

using namespace std;

class Area {
private:
    string name;
    list<Road> roads;

public:
    Area(string name);
    void addRoad(const Road& road);
    void removeRoad(const Road& road);
};

#endif // AREA_H
