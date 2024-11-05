#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>
#include <vector>
#include "Road.h"

using namespace std;

/**
 * @class Area
 * @brief Represents an area containing roads and manages traffic lights within those roads.
 *
 * The Area class allows for adding, removing, and connecting roads,
 * as well as controlling the traffic light states for all roads in the area.
 */
class Area {
private:
    string name; ///< The name of the area.
    shared_ptr<Road> head;

public:
    /**
     * @brief Constructs an Area with a specified name.
     * @param name The name of the area.
     */
    Area(string name);

    /**
     * @brief Sets all traffic lights on the roads in the area to red.
     */
    void setAllLightsToRed();

    /**
     * @brief Resets all traffic lights on the roads in the area to their default state.
     */
    void resetAllLights();

    /**
     * @brief Adds a road to the area.
     * @param road A shared pointer to the road to be added.
     */
    void addRoad(shared_ptr<Road> road);

    /**
     * @brief Removes a road from the area.
     * @param road A shared pointer to the road to be removed.
     */
    void removeRoad(shared_ptr<Road> road);



    /**
     * @brief Displays all roads in the area.
     */
    void displayRoads() const;
};

#endif // AREA_H
