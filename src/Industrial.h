#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "IndustrialFactory.h"
#include <memory> // Include for smart pointers

class Industrial : public Building {

    private:
    protected:
    public:
    Industrial();
    void build() override;
    unique_ptr<Building> clone() override; // Change to return unique_ptr<Building>
    string getType() override;

};

#endif
