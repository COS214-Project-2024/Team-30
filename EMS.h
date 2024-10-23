#ifndef EMS_H
#define EMS_H
#include "EmergencyServices.h"
class EMS : public EmergencyServices
{
  void handleRequest(Emergencies* emergency) override;

};

#endif