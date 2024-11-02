#ifndef ROADCARETAKER_H
#define ROADCARETAKER_H

#include <list>
#include "TrafficLight.h"

using namespace std;

class RoadCaretaker {
private:
    list<TrafficLight> lights;

public:
    void getLights();
};

#endif // ROADCARETAKER_H
