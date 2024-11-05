#ifndef RESOURCE_SUBJECT_H
#define RESOURCE_SUBJECT_H
#include "ResourceObserver.h"


class ResourceSubject
{
    private: 
        ResourceObserver* observerList;
    public: 
        //ResourceSubject();
        void attach(ResourceObserver obs);
        void detach(ResourceObserver obs);
        void notifyPowerPlant();
        void notifyWaterSupply();
        void notifyBuildings();

};

#endif
