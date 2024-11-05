#ifndef BUILT_H
#define BUILT_H

#include "BuildingState.h"

/**
 * @class Built
 * @brief Represents the "Built" state of a Building.
 *
 * The Built class implements state-specific behavior for buildings that are fully constructed
 * and operational. It provides concrete implementations of the methods defined in the BuildingState
 * interface for managing this state.
 */

class Built : public BuildingState{

    private:
    protected:
    public:
    /**
     * @brief Handles the behavior specific to the "Built" state.
     *
     * This method defines the actions taken while the building is in the "Built" state.
     */
    void handle() override;
    /**
     * @brief Changes the state of the Building to a different state.
     *
     * Implements the logic for transitioning from the "Built" state to another state.
     */
    void changeState() override;
    /**
     * @brief Gets the status of the "Built" state.
     *
     * @return A string indicating that the building is currently in a fully constructed state.
     */
    string getStatus() override;
    /**
     * @brief Clones the Built state object.
     *
     * Creates a deep copy of the current "Built" state.
     * @return A unique pointer to a new Built state object.
     */
    unique_ptr<BuildingState> clone() const override;


};

#endif
