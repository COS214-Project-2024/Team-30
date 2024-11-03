#include <iostream>
#include <vector>
#include <algorithm>

#include "BuildingComponent.h"
#include "BuildingComposite.h"
using namespace std;

// void add(std::unique_ptr<BuildingComponent> component) override {
//         buildings.push_back(std::move(component));
//     }

//  void remove(const BuildingComponent* component) override {
//         buildings.erase(
//             std::remove_if(buildings.begin(), buildings.end(),
//                            [&](const std::unique_ptr<BuildingComponent>& ptr) {
//                                return ptr.get() == component;
//                            }),
//             buildings.end()
//         );
//     }

// void showInfo() const override {
//         std::cout << "Building Group: " << name << std::endl;
//         for (const auto& building : buildings) {
//             building->showInfo();
//         }
//     }

void BuildingComposite::add(std::unique_ptr<BuildingComponent> component) {
    buildings.push_back(std::move(component));
}

void BuildingComposite::remove(const BuildingComponent *component) {
     buildings.erase(
            std::remove_if(buildings.begin(), buildings.end(),
                           [&](const std::unique_ptr<BuildingComponent>& ptr) {
                               return ptr.get() == component;
                           }),
            buildings.end()
        );
}

void BuildingComposite::showInfo() const {
    std::cout << "Building Group: " << name << std::endl;
        for (const auto& building : buildings) {
            building->showInfo();
        }
}



