#include "TrafficLight.h"
using namespace std;

int TrafficLight::numLights = 0;

TrafficLight::TrafficLight() : state('R'), id(++numLights){}

void TrafficLight::changeState()
{
    switch (state) {
        case 'R':
        {
            state = 'G';
            return;
        }
        case 'Y':
        {
            state = 'R';
            return;
        }
        case 'G':
        {
            state = 'Y';
            return;
        }
    }
}

char TrafficLight::getState() const
{
    return state;
}

int TrafficLight::getID() const
{
    return id;
}
