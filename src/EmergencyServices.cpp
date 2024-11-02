#include "EmergencyServices.h"
#include "Emergencies.h"

void EmergencyServices::handleRequest(std::shared_ptr<Emergencies> emergency)
{
    if (successor)
    {
        successor->handleRequest(emergency);
    }
    else
    {
        cout << "!!! ALERT: ALL EMERGENCY SERVICES UNAVAILABLE !!!" << endl;
        cout << ">>> THIS EMERGENCY CANNOT BE HANDLED <<<" << endl;
    }
}

void EmergencyServices::reduceDamage(std::shared_ptr<Emergencies> emergency, int reduction)
{
    int currentDamage = emergency->getDamage();
    emergency->setDamage(std::max(0, currentDamage - reduction));
}

EmergencyServices::~EmergencyServices() {}