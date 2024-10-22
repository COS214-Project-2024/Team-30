#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "CommercialFactory.h"

class Commercial : public Building{

    private:
    protected:
    public:
    void build();
    Commercial* clone();
};

#endif