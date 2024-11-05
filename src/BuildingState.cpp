#include <iostream>
#include <memory>  // Include for smart pointers

#include "BuildingState.h"
#include "Underconstruction.h"

void BuildingState::setBuilding(shared_ptr<Building> currbuilding) {
    this->building = currbuilding; // Set the weak_ptr
}

void BuildingState::setState() {
    // Create a shared_ptr for the new state
    shared_ptr<BuildingState> startState = make_shared<Underconstruction>(); // Use shared_ptr
    startState->handle(); // Call handle on the new state
}
