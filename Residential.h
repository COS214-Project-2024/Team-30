#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "ResidentialFactory.h"
#include <memory> // Include for smart pointers

class Residential : public Building {

    private:
    protected:
    
    public:
    Residential();
    void build() override;
    // std::unique_ptr<Building> clone() override; // Change to return unique_ptr<Building>
    // void displayInfo();
};

#endif
