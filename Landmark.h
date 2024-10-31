#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "LandmarkFactory.h"
#include <memory> // Include for smart pointers

class Landmark : public Building {

    private:
    protected:
    
    public:
    Landmark();
    void build() override;
    unique_ptr<Building> clone() override; // Change to return unique_ptr<Building>
    string getType() override;

};

#endif
