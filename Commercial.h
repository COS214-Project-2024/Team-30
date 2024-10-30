#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "CommercialFactory.h"
#include <memory> // Include for smart pointers

class Commercial : public Building {
    
    private:
    protected:
    public:
    Commercial();
    void build() override;
    // unique_ptr<Building> clone() override; // Return unique_ptr<Building>
};

#endif
