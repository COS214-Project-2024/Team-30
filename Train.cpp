#include "Train.h"

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
        from = to;
        this->removeAllPeople();
        cout << "The passengers have been moved to the destination via train!/n";
    } else {
        cout << "Invalid destination building." << endl;
    }
}
