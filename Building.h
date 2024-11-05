#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <memory> // Include for smart pointers
#include <algorithm>
#include "BuildingState.h"
#include "Emergencies.h"
#include "Citizen.h"
#include "Coal.h"
#include "Water.h"

class Emergencies;
class Utilities;

using namespace std;

/**
 * @class Building
 * @brief Represents a building in the system, which can have residents and utilities.
 */
class Building : public std::enable_shared_from_this<Building> 
{
protected:
    int id; ///< Unique ID of the building.
    unique_ptr<BuildingState> currState; ///< Current state of the building.
    int capacity; ///< Maximum number of residents.
    int buildingHealth; ///< Health status of the building.
    int price; ///< Price related to city budget.
    bool runningUtils; ///< Status of utility services.
    vector<shared_ptr<Citizen>> residents; ///< List of residents in the building.
    static int nextID; ///< Static counter for generating unique IDs.
    std::unique_ptr<Utilities> utils; ///< Utilities associated with the building.

    // Utilities resources
    int water;
    int power;
    int waste;
    int sewerage;

public:
    /** @brief Default constructor. */
    Building();

    /** @brief Destructor. */
    virtual ~Building();

    /** @brief Gets the maximum capacity of the building.
     *  @return Maximum number of residents the building can hold.
     */
    int getCapacity();

    /** @brief Builds the building (abstract function).
     *  @note This method must be implemented by derived classes.
     */
    virtual void build() = 0;

    /** @brief Gets the current state of the building.
     *  @return Pointer to the current BuildingState object.
     */
    BuildingState* getState();

    /** @brief Sets the building's state.
     *  @param state New state of the building.
     */
    void setState(unique_ptr<BuildingState> state);

    /** @brief Sets the capacity of the building.
     *  @param capacity The desired capacity.
     */
    void setCapacity(int capacity);

    /** @brief Processes the current state of the building. */
    void processState();

    /** @brief Gets the type of building (abstract function).
     *  @return String representing the type of building.
     */
    virtual string getType() = 0;

    /** @brief Displays information about the building. */
    void displayInfo();

    /** @brief Simulates an emergency in the building.
     *  @param emergency The emergency event to simulate.
     */
    void simulateEmergency(Emergencies &emergency);

    /** @brief Checks if a specific citizen is an occupant of the building.
     *  @param citizenID The ID of the citizen.
     *  @return True if the citizen is an occupant, false otherwise.
     */
    bool hasOccupant(int citizenID) const;

    /** @brief Prints the list of residents in the building. */
    void printResidents();

    /** @brief Checks if a citizen is contained in the residents list.
     *  @param citizen Shared pointer to a Citizen object.
     *  @return True if the citizen is a resident, false otherwise.
     */
    bool containsCitizen(shared_ptr<Citizen> citizen);

    /** @brief Gets the unique ID of the building.
     *  @return Integer representing the building's ID.
     */
    int getID();

    /** @brief Inflicts damage on the building.
     *  @param damage Amount of damage to apply to the building's health.
     */
    void takeDamage(int damage);

    /** @brief Updates the building's status. */
    void update();

    /** @brief Adds a citizen to the building's residents list.
     *  @param citizen Shared pointer to a Citizen object.
     */
    void addCitizen(shared_ptr<Citizen> citizen);

    /** @brief Removes a citizen from the building's residents list.
     *  @param citizen Shared pointer to a Citizen object.
     */
    void removeCitizen(shared_ptr<Citizen> citizen);

    /** @brief Notifies residents of an emergency situation.
     *  @param damage The severity of the emergency.
     */
    void notifyCitizensOfEmergency(int damage);

    /** @brief Sets the utilities for the building. */
    void setUtilities();

    /** @brief Sets the water supply level for the building.
     *  @param water The amount of water supply.
     */
    void setWater(int water);

    /** @brief Sets the power supply level for the building.
     *  @param power The amount of power supply.
     */
    void setPower(int power);

    /** @brief Sets the sewerage level for the building.
     *  @param sewerage The amount of sewerage handling capacity.
     */
    void setSewerage(int sewerage);

    /** @brief Sets the waste level for the building.
     *  @param waste The amount of waste handling capacity.
     */
    void setWaste(int waste);

    /** @brief Gets the water supply level.
     *  @return The amount of water supply.
     */
    int getWater();

    /** @brief Gets the power supply level.
     *  @return The amount of power supply.
     */
    int getPower();

    /** @brief Gets the sewerage level.
     *  @return The amount of sewerage capacity.
     */
    int getSewerage();

    /** @brief Gets the waste level.
     *  @return The amount of waste capacity.
     */
    int getWaste();

    /** @brief Receives water from a supply source.
     *  @param amount The amount of water received.
     */
    void receiveWater(int amount);

    /** @brief Receives electricity from a power source.
     *  @param amount The amount of electricity received.
     */
    void receiveElectricity(int amount);

    /** @brief Receives utility resources like coal and water.
     *  @param c Shared pointer to a Coal object.
     *  @param w Shared pointer to a Water object.
     */
    void receiveUtilities(shared_ptr<Coal> c, shared_ptr<Water> w);

    /** @brief Checks the construction status of the building. */
    void checkConstructionStatus();

    /** @brief Gets the list of residents in the building.
     *  @return Reference to a vector of shared pointers to Citizen objects.
     */
    std::vector<std::shared_ptr<Citizen>>& getResidents();

    /** @brief Clones the building.
     *  @return Unique pointer to a new Building object.
     */
    virtual unique_ptr<Building> clone() = 0;
};

#endif // BUILDING_H
