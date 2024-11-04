#include "TrafficLight.h"

using namespace std;

// Static variable initialization
int TrafficLight::numLights = 0;

/**
 * @brief Constructor for the TrafficLight class.
 *
 * Initializes the traffic light to the 'Red' state and assigns a unique ID
 * to each traffic light instance.
 */
TrafficLight::TrafficLight() : state('R'), id(++numLights) {}

/**
 * @brief Changes the state of the traffic light.
 *
 * This method cycles through the traffic light states:
 * - Red ('R') to Green ('G')
 * - Green ('G') to Yellow ('Y')
 * - Yellow ('Y') to Red ('R')
 */
void TrafficLight::changeState() {
    switch (state) {
        case 'R':
            state = 'G';
            return;
        case 'Y':
            state = 'R';
            return;
        case 'G':
            state = 'Y';
            return;
    }
}

/**
 * @brief Gets the current state of the traffic light.
 *
 * @return The current state of the traffic light as a character ('R', 'Y', or 'G').
 */
char TrafficLight::getState() const {
    return state;
}

/**
 * @brief Gets the unique ID of the traffic light.
 *
 * @return The ID of the traffic light instance.
 */
int TrafficLight::getID() const {
    return id;
}
