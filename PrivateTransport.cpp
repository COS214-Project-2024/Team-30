#include "PrivateTransport.h"

privateTransport::privateTransport(string name, int capacity, shared_ptr<Building> from): Transport(name,capacity,from){}

void privateTransport::Travel(shared_ptr<Building> to)
{
    {
        for (const auto& cit : passengers) {
            to->addCitizen(move(cit));
            cout << this->name << " has moved by private transport " << cit->getID() << endl;
        }
        from = to;
    }
}
