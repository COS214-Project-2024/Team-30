#include <iostream>
#include <memory>  // Include for smart pointers

#include "Destroyed.h"
#include "BuildingState.h"
#include "Underconstruction.h"

void Destroyed::handle() {
    std::cout << "Building has been destroyed." << std::endl;
}

void Destroyed::changeState() {
    // Create a unique_ptr for the new state
    std::unique_ptr<BuildingState> state_ = std::make_unique<Underconstruction>(); // Use unique_ptr
    state_->handle(); // Call handle on the new state
}

std::string Destroyed::getStatus() {
    return "Destroyed";
}
