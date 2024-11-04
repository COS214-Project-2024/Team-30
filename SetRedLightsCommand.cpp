#include "SetRedLightsCommand.h"
#include <chrono>
#include <thread>

/**
 * @brief Executes the command to set all traffic lights in the area to red.
 *
 * This method changes the state of all traffic lights in the associated area to red,
 * waits for a duration of 5 seconds to simulate the red light duration,
 * and then resets all lights to their original state.
 */
void SetRedLightsCommand::execute() {
    if (area) {
        area->setAllLightsToRed();
        this_thread::sleep_for(chrono::seconds(5)); // makes it wait
        area->resetAllLights(); // Reset lights to their original state after a delay
    }
}
