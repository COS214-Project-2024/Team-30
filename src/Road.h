#ifndef ROAD_H
#define ROAD_H

#include <string>
#include <list>
#include "Building.h"
#include "Sign.h"
#include "TrafficLight.h"

using namespace std;

class Road {
private:
    string name;
    list<TrafficLight> lights;
    list<Building> buildings;
    list<Sign> signs;
    Road* left;
    Road* right;

public:
    Road(string name);
    void addBuilding(const Building& building);
    void removeBuilding(const Building& building);
    void addSign(const Sign& sign);
    void removeSign(const Sign& sign);
    void addLight(const TrafficLight& light);
    void removeLight(const TrafficLight& light);
};

#endif // ROAD_H
