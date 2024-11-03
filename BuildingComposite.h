#ifndef BUILDINGCOMPOSITE_H
#define BUILDINGCOMPOSITE_H

#include <iostream>
#include <vector>

#include "BuildingComponent.h"
using namespace std;

class BuildingComposite : public BuildingComponent {
private:
    std::vector<std::unique_ptr<BuildingComponent>> buildings;
    std::string name;

public:
    BuildingComposite();
    
    BuildingComposite(const std::string& name) : name(name) {}

    void add(std::unique_ptr<BuildingComponent> component) override;

    void remove(const BuildingComponent* component) override;

    void showInfo() const override;
};

#endif