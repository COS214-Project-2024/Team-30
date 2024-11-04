#include "SetRedLightsCommand.h"
#include <chrono>
#include <thread>

void SetRedLightsCommand::execute() {
    if (area) {
        area->setAllLightsToRed();
        this_thread::sleep_for(chrono::seconds(5)); //makes it wait
        area->resetAllLights(); // Reset lights to their original state after a delay
    }
}
