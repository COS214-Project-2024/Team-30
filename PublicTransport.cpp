#include "PublicTransport.h"
#include <iostream>

publicTransport::publicTransport(std::string name, int capacity, shared_ptr<Building> from) : Transport(name,capacity,from){}

void publicTransport::Travel(shared_ptr<Building> to) {
    if (to) {
        cout << "Traveling to " << to->getName() << " by public transport.\n";
        for (const auto& cit : passengers) {
            to->addCitizen(cit);
            cout << "Passenger with ID " << cit->getID() << " has been transported to " << to->getName() << ".\n";
        }
        passengers.clear();
        from = to;
    } else {
        cout << "Invalid destination building.\n";
    }
}
