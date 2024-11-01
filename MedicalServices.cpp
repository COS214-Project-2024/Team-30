#include "MedicalServices.h"
#include <iostream>

void MedicalServices::handleRequest(std::shared_ptr<Emergencies> emergency) {
    if (emergency->getTypeOfEmergency() == "Earthquake" && emergency->getDamage() > 50) {
        std::cout << "Medical Services are assisting injured citizens due to severe earthquake damage." << std::endl;
        reduceDamage(emergency, 15);
        // emergency->notifyCitizensOfResponse("Medical Services");
    } else{
        EmergencyServices::handleRequest(emergency);
    }
}
