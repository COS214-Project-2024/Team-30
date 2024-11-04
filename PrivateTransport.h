#ifndef PRIVATETRANSPORT_H
#define PRIVATETRANSPORT_H

#include "Transport.h"

using namespace std;

class privateTransport : public Transport {
public:
    privateTransport(string name, int capacity, shared_ptr<Building> from);
    void Travel(shared_ptr<Building> to) override ;
};

#endif // PRIVATETRANSPORT_H

