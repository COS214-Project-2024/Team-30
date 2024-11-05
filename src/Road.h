#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include "Sign.h"
#include "TrafficLight.h"
#include "Building.h"

// Forward declaration to avoid circular dependency
class Building;

using namespace std;

/**
 * @brief Represents a road in the traffic system.
 *
 * The Road class maintains a collection of buildings, signs, and a traffic light,
 * and allows for managing connections to other roads.
 */
class Road : public enable_shared_from_this<Road> {
private:
    int id; ///< The ID of the road.
    vector<shared_ptr<Building>> buildings; ///< Buildings located on this road.
    vector<Sign> signs; ///< Signs associated with this road.
    unique_ptr<TrafficLight> light; ///< Traffic light for this road.
    char state; ///< The state of the traffic light, used as a memento.
    shared_ptr<Road> next; ///< Pointer to the next road.

public:
    static int numSigns;

    /**
     * @brief Constructs a Road object.
     */
    Road();

    /**
     * @brief Sets the traffic light on this road to red.
     */
    void setLightRed();

    /**
     * @brief Resets the traffic light to its previous state.
     */
    void resetLight();

    /**
     * @brief Adds a building to this road.
     * 
     * @param building A shared pointer to the building to be added.
     */
    void addBuilding(shared_ptr<Building> building);

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
     * @brief Gets the ID of the road.
     *
     * @return The ID of the road.
     */
    int getID() const;

    /**
     * @brief Sets the next road in the sequence.
     * 
     * @param r A shared pointer to the next road.
     */
    void setNext(shared_ptr<Road> r);

    /**
     * @brief Gets the next road in the sequence.
     *
     * @return A shared pointer to the next road.
     */
    shared_ptr<Road> getNext();

    /**
     * @brief Checks if the road contains a specific building.
     *
     * @param b A shared pointer to the building to check for.
     * @return True if the building is found, otherwise false.
     */
    bool containsBuilding(shared_ptr<Building> b);

    vector<Sign> getSigns();

    ~Road() = default; ///< Default destructor.
};

#endif // ROAD_H
