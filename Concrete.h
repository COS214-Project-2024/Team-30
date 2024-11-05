#ifndef CONCRETE_H
#define CONCRETE_H
#include "Resource.h"


class Concrete : public Resource
{
    private: 
        int capacity;

    public: 
        Concrete(int capacity);

        int getCapacity() const override;
        void refill(int amount) override;
        int use(int amount) override;

};

#endif