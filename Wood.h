#ifndef WOOD_H
#define WOOD_H

#include "Resource.h"

using namespace std;
#include <iostream>
#include <memory>

class Wood : public Resource
{
    private: 
        //int capacity;

    public: 
        Wood(int capacity);

        int getCapacity() const override;
        void refill(int amount) override;
        int use(int amount) override;

};

#endif