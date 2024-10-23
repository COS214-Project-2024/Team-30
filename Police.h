#ifndef POLICE_H
#define POLICE_H
#include "EmergencyServices.h"
class Police : public EmergencyServices
{
  void handleRequest(Emergencies* emergency) override;

};

#endif