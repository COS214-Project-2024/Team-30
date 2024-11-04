#include "Area.h"

Area::Area(string name) : name(move(name)) {}

// Method to add a road to the area
void Area::addRoad(shared_ptr<Road> newRoad) {
    roads.push_back(newRoad);
}

void Area::connectRoads(const std::shared_ptr<Road>& from, const std::shared_ptr<Road>& toLeft, const std::shared_ptr<Road>& toRight, const std::shared_ptr<Road>& toStraight) {
    from->left = toLeft;
    from->right = toRight;
    from->straight = toStraight;
}

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

void Area::setAllLightsToRed()
{
    for (const auto& road : roads) {
        road->setLightRed();
    }
}

void Area::resetAllLights()
{
    for (const auto& road : roads) {
        road->resetLight();
    }
}