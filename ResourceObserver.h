#ifndef RESOURCE_OBSERVER_H
#define RESOURCE_OBSERVER_H

class ResourceObserver
{
    private: 
        // observerState: State* 
        //subject: ConcreteSubjects (buildings, powerPlant, waterSupply)
    public: 
        ResourceObserver();
        void updateWaterSupply();
        void updatePowerPlant(); 
        void updateBuildings();
        

};

#endif