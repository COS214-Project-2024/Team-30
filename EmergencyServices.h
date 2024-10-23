#ifndef EMERGENCYSERVICES_H
#define EMERGENCYSERVICES_H

#include "Emergencies.h"

class EmergencyServices
{
    protected:
        EmergencyServices* successor;

    public:
    virtual void handleRequest(Emergencies* emergency) = 0;
};

#endif