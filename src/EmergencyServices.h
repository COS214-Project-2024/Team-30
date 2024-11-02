#ifndef EMERGENCYSERVICES_H
#define EMERGENCYSERVICES_H

#include <memory>
#include <iostream>

class Emergencies;
using namespace std;

class EmergencyServices {
protected:
    std::shared_ptr<EmergencyServices> successor;

public:
    virtual ~EmergencyServices() = default;

    virtual void handleRequest(std::shared_ptr<Emergencies> emergency);

    virtual void reduceDamage(std::shared_ptr<Emergencies> emergency, int reduction);
};

#endif // EMERGENCYSERVICES_H
