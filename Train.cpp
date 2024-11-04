#include "Train.h"

/**
 * @brief Constructs a Train object with a specified name, capacity, and starting building.
 *
 * This constructor also accepts a traffic command that will be executed during travel.
 *
 * @param name The name of the train.
 * @param capacity The maximum capacity of passengers the train can carry.
 * @param from A shared pointer to the building from which the train departs.
 * @param cmd A shared pointer to a trafficCommand that controls traffic lights during travel.
 */
Train::Train(string name, int capacity, shared_ptr<Building> from, shared_ptr<trafficCommand> cmd)
        : publicTransport(name, capacity, from)
{
    this->trafficCmd = cmd;
}

/**
 * @brief Travels from the current building to the specified destination building.
 *
 * Executes the associated traffic command to set all traffic lights to red
 * before transporting passengers to the destination building.
 *
 * @param to A shared pointer to the building to which the train will travel.
 */
void Train::Travel(shared_ptr<Building> to) {
    if (trafficCmd) {
        trafficCmd->execute(); // Trigger the command to set all lights to red
    }

    if (to) {
        for (const auto& cit : passengers) {
            to->addCitizen(cit);
            cout << name << " transported citizen with ID " << cit->getID() << " to building: " << to->getName() << endl;
        }
        passengers.clear();  // Clear all passengers after they have been moved.
        from = to;           // Update the 'from' building to the new location.
    } else {
        cout << "Invalid destination building." << endl;
    }
}