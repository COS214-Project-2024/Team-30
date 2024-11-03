#ifndef BUILDINGCOMPONENT_H
#define BUILDINGCOMPONENT_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Component
class BuildingComponent {
public:
    virtual ~BuildingComponent() = default;
    virtual void showInfo() const;
    virtual void add(std::unique_ptr<BuildingComponent> component) ;
    virtual void remove(const BuildingComponent* component) ;
};

#endif