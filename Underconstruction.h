#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"

/**
 * @class Underconstruction
 * @brief Represents the "Under Construction" state of a Building.
 *
 * The Underconstruction class implements state-specific behavior for buildings
 * that are currently under construction. It provides concrete implementations
 * of the methods defined in the BuildingState interface.
 */

class Underconstruction : public BuildingState{

    private:
    protected:

    public:
    /**
     * @brief Handles the behavior specific to the "Under Construction" state.
     *
     * This method defines the actions taken while the building is in the "Under Construction" state.
     */
    void handle() override;

    /**
     * @brief Changes the state of the Building to a different state.
     *
     * Implements the logic for transitioning from the "Under Construction" state to another state.
     */
    void changeState() override;

    /**
     * @brief Gets the status of the "Under Construction" state.
     *
     * @return A string indicating that the building is currently under construction.
     */
    string getStatus() override;

    
    unique_ptr<BuildingState> clone() const override;

};

#endif
