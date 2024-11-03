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
    unique_ptr<Building> clone() override; // Change to return unique_ptr<Building>
    string getType() override;

    // Residential(const std::string& name) : Building(name) {}

    // void showInfo() const override {
    //     std::cout << "Residential Building: " << name << std::endl;
    // }
};

#endif
