#ifndef POPULATION_H
#define POPULATION_H

#include "Government.h"
class Population :public Government{
    public:
        int getPopulation();
        void setPopulation(int a);
    private: 
     int population;
};

#endif