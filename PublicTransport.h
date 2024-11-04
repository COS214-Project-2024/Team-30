#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

#include "Transport.h"

using namespace std;

class publicTransport : public Transport{
public:
    publicTransport(string name, int capacity, shared_ptr<Building> from);
    virtual void Travel(shared_ptr<Building> to) override;
};

#endif // PUBLICTRANSPORT_H