#include "Road.h"

int Road::numSigns = 0;

/**
 * @brief Constructs a new Road object.
 *
 * @param name The name of the road.
 */
Road::Road() : id(++numSigns) {}

/**
 * @brief Adds a building to the road.
 *
 * @param building Unique pointer to the building to be added.
 */
void Road::addBuilding(unique_ptr<Building> building) {
    if (building) {
        buildings.push_back(move(building));
    }
}

/**
 * @brief Adds a sign to the road.
 *
 * @param sign The sign to be added to the road.
 */
void Road::addSign(const Sign& sign) {
    signs.push_back(sign);
}

/**
 * @brief Adds a traffic light to the road.
 *
 * Only one traffic light can be added to the road. If a traffic light
 * already exists, a message is printed.
 *
 * @param light Unique pointer to the traffic light to be added.
 */
void Road::addLight(unique_ptr<TrafficLight> light) {
    if (light && !this->light) {
        this->light = move(light);
        return;
    }
    cout << "This road already has a traffic light" << endl;
}

/**
 * @brief Removes the traffic light from the road.
 *
 * @return true if the light was removed successfully, false if no light was present.
 */
bool Road::removeLight() {
    if (light) {
        light = nullptr;
        return true;
    }
    return false;
}

/**
 * @brief Gets the name of the road.
 *
 * @return The name of the road as a string.
 */
string Road::getName() const {
    return name;
}

/**
 * @brief Sets the traffic light state to red ('R').
 *
 * If a traffic light is present, changes its state to red and saves
 * the previous state for future restoration.
 */
void Road::setLightRed() {
    if (light) {
        state = light->getState();
        light->setState('R');
    }
}

/**
 * @brief Resets the traffic light to its previous state.
 *
 * If a traffic light is present and the previous state is valid,
 * it is reset to that state.
 */
void Road::resetLight() {
    if (light && state != 'N') {
        light->setState(state);
    }
}

void Road::setNext(shared_ptr<Road> road)
{
    this->next = road;
}

shared_ptr<Road> Road::getNext()
{
    return this->next;
}
