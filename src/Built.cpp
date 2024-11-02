#include <iostream>
#include <memory>  // Include for smart pointers

#include "Built.h"
#include "Destroyed.h"
#include "BuildingState.h"

void Built::handle()
{
    std::cout << "Building has been built" << std::endl;
}

void Built::changeState()
{
    // Create a shared_ptr for the new state
    shared_ptr<BuildingState> state = make_shared<Destroyed>(); // Use shared_ptr
    state->handle(); // Call handle on the new state
}

string Built::getStatus()
{
    return "Built";
}

unique_ptr<BuildingState> Built::clone() const
{
    return std::make_unique<Built>(*this);
}
