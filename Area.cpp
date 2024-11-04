#include "Area.h"

/**
 * @brief Constructs an Area with a specified name.
 * @param name The name of the area.
 */
Area::Area(string name) : name(move(name)) {}

/**
 * @brief Adds a road to the area.
 * @param newRoad new shared pointer
 */
void Area::addRoad(shared_ptr<Road> newRoad) {
    shared_ptr<Road> node = head;
    if (!head)
    {
        head = newRoad;
        newRoad->setNext(head);
    }
    while (node->getNext()!= head)
        node = node->getNext();
    node->setNext(newRoad);
    newRoad->setNext(head);
}

/**
 * @brief Connects roads in the area.
 * @param from A shared pointer to the originating road.
 * @param toLeft shared pointer to left road
 * @param toRight shared pointer to right road
 * @param toStraight shared pointer to straight road
 */


/**
 * @brief displays adjacency list
 */
void Area::displayRoads() const {
    shared_ptr<Road> node;
    node = head;
    cout << "Roads in this area:\n" << node->getName();
    while (node->getNext() != head)
    {
        cout << node->getName() << endl;
    }

}

/**
 * @brief Sets all traffic lights to stop all cars
 */
void Area::setAllLightsToRed() {
    shared_ptr<Road> node = head;
    node->setLightRed();
    while (node->getNext() != head)
        node->setLightRed();
}

/**
 * @brief Resets all traffic lights on the roads in the area as 'memento'
 */
void Area::resetAllLights() {
    shared_ptr<Road> node = head;
    node->resetLight();
    while (node->getNext() != head)
        node->resetLight();
}

