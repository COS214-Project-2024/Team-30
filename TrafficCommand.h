#ifndef TRAFFICCOMMAND_H
#define TRAFFICCOMMAND_H

#include <list>
#include "TrafficLight.h"

using namespace std;

class trafficCommand {
public:
    virtual void execute() = 0;
    virtual list<TrafficLight> getLights() = 0;
};

#endif // TRAFFICCOMMAND_H
