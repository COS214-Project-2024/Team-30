#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "LandmarkFactory.h"

class Landmark : public Building{

    private:
    protected:
    
    public:
    Landmark();
    void build() override;
    Landmark* clone() override;
};

#endif