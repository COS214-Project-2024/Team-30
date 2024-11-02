#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <memory>  // Include for smart pointers
#include <string>  // Include for std::string

using namespace std;

class Building;

class BuildingState {

    private:
    protected:
    weak_ptr<Building> building; // Use weak_ptr to prevent circular references

    public:
    virtual ~BuildingState() {}

    void setBuilding(shared_ptr<Building> currbuilding); // Accept shared_ptr
    void setState();
    virtual void handle() = 0;
    virtual void changeState() = 0;
    virtual string getStatus() = 0;
     virtual unique_ptr<BuildingState> clone() const = 0;  // Clone for deep copy. this will ensure that when we use prototype to create objects, they wont share states.
};

#endif