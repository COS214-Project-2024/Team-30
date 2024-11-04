#include "Taxi.h"

void Taxi::Travel(shared_ptr<Building> to) {
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