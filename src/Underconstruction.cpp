#include <iostream>
#include "Underconstruction.h"
#include "Built.h"
#include "BuildingState.h"
#include <memory> // Include for smart pointers

void Underconstruction::handle()
{
    std::cout << "Building is under construction." << std::endl;
}

void Underconstruction::changeState()
{
    unique_ptr<BuildingState> state_ = std::make_unique<Built>(); // Use smart pointer
    state_->handle();
}

std::string Underconstruction::getStatus()
{
    return "Underconstruction";
}

unique_ptr<BuildingState> Underconstruction::clone() const
{
    return std::make_unique<Underconstruction>(*this);
}
