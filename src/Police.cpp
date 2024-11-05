#include "Police.h"
#include "Emergencies.h"
#include <iostream>

void Police::handleRequest(std::shared_ptr<Emergencies> emergency) {
    if (emergency->getTypeOfEmergency() == "Theft") {
        std::cout << "Police are handling the theft incident!" << std::endl;
        reduceDamage(emergency, 10);
    } else
    {
     EmergencyServices::handleRequest(emergency);   
    }
}
