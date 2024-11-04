#include "Train.h"

Train::Train(string name, int capacity, shared_ptr<Building> from,shared_ptr<trafficCommand> cmd): publicTransport(name,capacity,from)
{
    this->trafficCmd = cmd;
}

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
