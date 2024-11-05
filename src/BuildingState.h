#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <memory>  // Include for smart pointers
#include <string>  // Include for std::string

using namespace std;

class Building;

/**
 * @class BuildingState
 * @brief Abstract base class representing the state of a Building.
 *
 * The BuildingState class defines the interface for handling state-specific behavior
 * of a Building. Derived classes must implement the abstract methods to define
 * specific state behaviors and transitions.
 */

class BuildingState {

    private:
    protected:
    /**
     * @brief Weak reference to the associated Building.
     *
     * Using weak_ptr prevents circular references between Building and BuildingState,
     * helping manage memory and avoid potential memory leaks.
     */
    weak_ptr<Building> building; // Use weak_ptr to prevent circular references

    public:
    /**
     * @brief Virtual destructor for BuildingState.
     */
    virtual ~BuildingState() {}

    /**
     * @brief Sets the associated Building object.
     *
     * Assigns the current Building instance to the state using a shared pointer.
     * @param currbuilding Shared pointer to the current Building object.
     */
    void setBuilding(shared_ptr<Building> currbuilding); // Accept shared_ptr

    /**
     * @brief Sets the associated Building object.
     *
     * Assigns the current Building instance to the state using a shared pointer.
     * @param currbuilding Shared pointer to the current Building object.
     */
    void setState();

    /**
     * @brief Handles state-specific behavior.
     *
     * This pure virtual function must be implemented by derived classes to perform
     * actions associated with the current state.
     */
    virtual void handle() = 0;

    /**
     * @brief Changes the state of the Building to a new state.
     *
     * This pure virtual function must be implemented by derived classes to handle
     * transitions to a different state.
     */
    virtual void changeState() = 0;

    /**
     * @brief Gets the status of the current state.
     *
     * This pure virtual function must be implemented by derived classes to return
     * a string representing the current state status.
     * @return A string indicating the status of the current state.
     */
    virtual string getStatus() = 0;

    /**
     * @brief Clones the BuildingState object.
     *
     * This pure virtual function must be implemented by derived classes to create a deep copy
     * of the BuildingState. Ensures that when using the prototype pattern, objects do not share states.
     * @return A unique pointer to a new cloned BuildingState object.
     */
     virtual unique_ptr<BuildingState> clone() const = 0;  // Clone for deep copy. this will ensure that when we use prototype to create objects, they wont share states.
};

#endif
