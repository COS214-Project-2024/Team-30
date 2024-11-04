#include <iostream>
#include "Transport.h"

using namespace std;

Transport::Transport(string name, int capacity, shared_ptr<Building> from)
        : name(move(name)), capacity(capacity), from(move(from)) {}

/**
 * @brief Adds a citizen as a passenger to the transport if they are present in the starting building.
 *
 * Checks if the specified citizen is in the building and not already a passenger.
 * If the transport is not at full capacity, the citizen is added to the passenger list.
 *
 * @param c A shared pointer to the Citizen to be added as a passenger.
 */
void Transport::addPeople(shared_ptr<Citizen> c) {
    if (from->containsCitizen(c)) { // Check if the citizen is in the building
        auto it = std::find(passengers.begin(), passengers.end(), c);
        if (it == passengers.end()) // Check if the passenger isn't already in the vehicle
        {
            if (passengers.size() < capacity) {
                passengers.push_back(c);
                cout << "Passenger " << c->getID() << " added successfully." << endl;
                from->removeCitizen(c);
            } else {
                cout << "Transport is at full capacity. Cannot add more passengers." << endl;
            }
        } else {
            cout << "Passenger is already in the transport." << endl;
        }
    }
}

/**
 * @brief Removes a specified citizen from the transport.
 *
 * Checks if the transport is empty before attempting to remove the citizen.
 * If the citizen is found, they are removed from the passenger list and added back to the building.
 *
 * @param c A shared pointer to the Citizen to be removed from the transport.
 */
void Transport::removePeople(shared_ptr<Citizen> c) {
    if (passengers.empty())
    {
        cout << "Transport is empty" << endl;
        return;
    }
    auto it = find(passengers.begin(), passengers.end(), c);
    if (it != passengers.end()) {
        passengers.erase(it);
        from->addCitizen(move(c));
    } else {
        cout << "Passenger not found in the transport." << endl;
    }
}

/**
 * @brief Removes all passengers from the transport and adds them back to the building.
 *
 * Iteratively transfers each passenger back to the building from which they were transported.
 */
void Transport::removeAllPeople() {
    while (!passengers.empty()) {
        from->addCitizen(passengers.back());
        passengers.pop_back();
    }
}

/**
 * @brief Prints the IDs of all passengers currently in the transport.
 *
 * If there are no passengers, a message is displayed indicating that the transport is empty.
 */
void Transport::printPassengers() {
    if (passengers.empty()) {
        cout << "No passengers in the vehicle." << endl;
        return;
    }
    cout << "Passengers' ID numbers:\n";
    for (const auto& passenger : passengers) {
        if (passenger) {
            cout << passenger->getID() << "\n";
        }
    }
    cout << endl;
}
