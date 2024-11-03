#ifndef COAL_H
#define COAL_H
#include "Resource.h"

class Coal : public Resource
{
    private: 
        //int capacity;

    public: 
        Coal(int capacity);

        int getCapacity() const override;
        void refill(int amount) override;
        void use(int amount) override;

};

#endif