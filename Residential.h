#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "ResidentailFactory.h"


class Residential : public Building{

    private:
    protected:
    public:
    void build();
    Residential* clone();
    //void displayInfo();
};

#endif