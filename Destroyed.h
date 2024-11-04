#ifndef DESTROYED_H
#define DESTROYED_H

#include "BuildingState.h"

/**
 * @class Destroyed
 * @brief Represents the "Destroyed" state of a Building.
 *
 * The Destroyed class implements state-specific behavior for buildings
 * that have been destroyed. It provides concrete implementations of the methods
 * defined in the BuildingState interface for managing this state.
 */

class Destroyed : public BuildingState{

    private:
    protected:
    public:
    void handle() override;
    void changeState() override;
    string getStatus() override;
    unique_ptr<BuildingState> clone() const override;

};

#endif
