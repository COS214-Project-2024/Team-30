#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>
#include <vector>
#include "Road.h"

using namespace std;

class Area {
private:
    string name;
    vector<std::shared_ptr<Road>> roads;
public:
    void setAllLightsToRed();
    void resetAllLights();
    Area(string name);
    void addRoad(shared_ptr<Road> road);
    void removeRoad(shared_ptr<Road> road);
    void connectRoads(const shared_ptr<Road>& from, const shared_ptr<Road>& toLeft, const shared_ptr<Road>& toRight, const shared_ptr<Road>& toStraight);
    void displayRoads() const;
};

#endif // AREA_H
