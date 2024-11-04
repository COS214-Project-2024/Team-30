#ifndef Steel_H
#define Steel_H
#include "Resource.h"

class Steel : public Resource
{
    private: 
        //int capacity;

    public: 
        Steel(int capacity);

        int getCapacity() const override;
        void refill(int amount) override;
        int use(int amount) override;

};

#endif