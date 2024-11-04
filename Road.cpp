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

class Building; //forward declaration

/**
 * @brief Represents a road in the traffic system.
 *
 * The Road class maintains a collection of buildings, signs, and a traffic light,
 * and allows for managing connections to other roads (left, right, straight).
 */
class Road {
private:
    string name;  ///< The name of the road.
    vector<unique_ptr<Building>> buildings; ///< Buildings located on this road.
    vector<Sign> signs; ///< Signs associated with this road.
    unique_ptr<TrafficLight> light; ///< Traffic light for this road.
    char state; ///< The state of the road, acting as a memento.

public:
    /**
     * @brief Constructs a Road object with a specified name.
     *
     * @param name The name of the road.
     */
    Road(const string& name);

    /**
     * @brief Sets the traffic light on this road to red.
     *
     * Changes the state of the traffic light to indicate that vehicles must stop.
     */
    void setLightRed();

    /**
     * @brief Resets the traffic light to its default state.
     *
     * This method returns the traffic light to its original setting (e.g., green).
     */
    void resetLight();

    shared_ptr<Road> left;   ///< Pointer to the road on the left.
    shared_ptr<Road> right;  ///< Pointer to the road on the right.
    shared_ptr<Road> straight; ///< Pointer to the road straight ahead.

    /**
     * @brief Adds a building to this road.
     *
     * @param building A unique pointer to the building to be added.
     */
    void addBuilding(unique_ptr<Building> building);

    /**
     * @brief Adds a sign to this road.
     *
     * @param sign The sign to be added.
     */
    void addSign(const Sign& sign);

    /**
     * @brief Adds a traffic light to this road.
     *
     * @param light A unique pointer to the traffic light to be added.
     */
    void addLight(unique_ptr<TrafficLight> light);

    /**
     * @brief Removes the traffic light from this road.
     *
     * @return True if the light was removed successfully, otherwise false.
     */
    bool removeLight();

    /**
     * @brief Gets the name of the road.
     *
     * @return The name of the road.
     */
    string getName() const;

    ~Road() = default; ///< Default destructor.
};

#endif // ROAD_H
