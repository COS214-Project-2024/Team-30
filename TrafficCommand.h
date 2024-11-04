#ifndef TRAFFICCOMMAND_H
#define TRAFFICCOMMAND_H

#include <list>
#include "TrafficLight.h"
#include "Area.h"

using namespace std;

class trafficCommand {
public:
    virtual ~trafficCommand() = default;
    virtual void execute() = 0;
};

#endif // TRAFFICCOMMAND_H