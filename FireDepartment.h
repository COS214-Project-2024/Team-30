#ifndef FIREDEPARTMENT_H
#define FIREDEPARTMENT_H
#include "EmergencyServices.h"
class FireDepartment : public EmergencyServices
{
  void handleRequest(Emergencies* emergency) override;

};

#endif