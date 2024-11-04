#ifndef FIREFIGHTERS_H
#define FIREFIGHTERS_H

#include "EmergencyServices.h"

class Firefighters : public EmergencyServices {
public:
    void handleRequest(std::shared_ptr<Emergencies> emergency) override;
};

#endif // FIREFIGHTERS_H
