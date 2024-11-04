#ifndef COAL_H
#define COAL_H
#include "Resource.h"

class Coal : public Resource
{
    private: 
        //int capacity;

    public: 
        Coal(int capacity);

        int getCapacity() ;
        void refill(int amount) ;
        int use(int amount) ;

};

#endif