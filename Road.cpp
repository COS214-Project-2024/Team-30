
#include "Road.h"

Road::Road(const string& name) : name(name){}

void Road::addBuilding(unique_ptr<Building> building) {
    if (building) {
        buildings.push_back(move(building));
    }
}

void Road::addSign(const Sign& sign) {
    signs.push_back(sign);
}

void Road::addLight(unique_ptr<TrafficLight> light) {
    if (light && !this->light) {
        this->light = move(light);
        return;
    }
    cout << "this road already has a traffic light" << endl;
}

bool Road::removeLight() {
    if (light)
    {
        light = nullptr;
        return true;
    }
    return false;
}

string Road::getName() const {
    return name;
}

void Road::setLightRed()
{
    if (light)
    {
        state = light->getState();
        light->setState('R');
    }
}

void Road::resetLight()
{
    if (light && state != 'N')
    {
        light->setState(state);
    }
}
