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
    roads.push_back(newRoad);
}

/**
 * @brief Connects roads in the area.
 * @param from A shared pointer to the originating road.
 * @param toLeft shared pointer to left road
 * @param toRight shared pointer to right road
 * @param toStraight shared pointer to straight road
 */
void Area::connectRoads(const std::shared_ptr<Road>& from, const std::shared_ptr<Road>& toLeft,
                        const std::shared_ptr<Road>& toRight, const std::shared_ptr<Road>& toStraight) {
    from->left = toLeft;
    from->right = toRight;
    from->straight = toStraight;
}

/**
 * @brief displays adjacency list
 */
void Area::displayRoads() const {
    for (const auto& road : roads) {
        std::cout << "Road " << road->getName() << " connections:\n";
        if (road->left) std::cout << "  Left: " << road->left->getName() << "\n";
        if (road->right) std::cout << "  Right: " << road->right->getName() << "\n";
        if (road->straight) std::cout << "  Straight: " << road->straight->getName() << "\n";
        if (!road->left && !road->right && !road->straight) {
            std::cout << "  No connections\n";
        }
    }
}

/**
 * @brief Sets all traffic lights to stop all cars
 */
void Area::setAllLightsToRed() {
    for (const auto& road : roads) {
        road->setLightRed();
    }
}

/**
 * @brief Resets all traffic lights on the roads in the area as 'memento'
 */
void Area::resetAllLights() {
    for (const auto& road : roads) {
        road->resetLight();
    }
}
