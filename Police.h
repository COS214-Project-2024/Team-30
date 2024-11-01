#ifndef POLICE_H
#define POLICE_H
#include "EmergencyServices.h"
class Police : public EmergencyServices
{
  void handleRequest(std::shared_ptr<Emergencies> emergency) override;

};

#endif