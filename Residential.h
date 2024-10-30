#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "ResidentailFactory.h"


class Residential : public Building{

    private:
    protected:
    
    public:
    Residential();
    void build() override;
    Residential* clone() override;
    //void displayInfo();
};

#endif