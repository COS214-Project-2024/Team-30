#include "Firefighters.h"
#include "Emergencies.h"
#include <iostream>

void Firefighters::handleRequest(std::shared_ptr<Emergencies> emergency)
{
    if (emergency->getTypeOfEmergency() == "Fire")
    {
        std::cout << "Firefighters are extinguishing the fire!" << std::endl;
        reduceDamage(emergency, 20);
        // emergency->notifyCitizensOfResponse("Firefighters");
    }
    else
    {
        EmergencyServices::handleRequest(emergency);
    }
}
