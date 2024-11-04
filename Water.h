#ifndef WATER_H
#define WATER_H
#include "Resource.h"


class Water : public Resource
{
    private: 
        //int capacity;

    public: 
        Water(int capacity);

        int getCapacity() const override;
        void refill(int amount) override;
        int use(int amount) override;


};

#endif