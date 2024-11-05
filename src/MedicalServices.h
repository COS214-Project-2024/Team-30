#ifndef MEDICALSERVICES_H
#define MEDICALSERVICES_H

#include "EmergencyServices.h"

class MedicalServices : public EmergencyServices {
public:
    void handleRequest(std::shared_ptr<Emergencies> emergency) override;
};

#endif // MEDICALSERVICES_H
