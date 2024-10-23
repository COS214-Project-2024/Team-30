#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "IndustrialFactory.h"

class Industrial : public Building{

    private:
    protected:
    public:
    void build();
    Industrial* clone();
};

#endif