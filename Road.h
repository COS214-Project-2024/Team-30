#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include "Building.h"
#include "Sign.h"
#include "TrafficLight.h"

using namespace std;

class Building;

class Road {
private:
    string name;
    vector<unique_ptr<Building>> buildings;
    vector<Sign> signs;
    unique_ptr<TrafficLight> light;
    char state;
public:
    void setLightRed();
    void resetLight();
    shared_ptr<Road> left;
    shared_ptr<Road> right;
    shared_ptr<Road> straight;
    Road(const string& name);
    void addBuilding(unique_ptr<Building> building);
    void addSign(const Sign& sign);
    //bool removeSign(Sign sign);
    void addLight(unique_ptr<TrafficLight> light);
    bool removeLight();
    string getName() const;                     // Return the road's name
    ~Road() = default;
};

#endif // ROAD_H