#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

#include "Transport.h"

using namespace std;

class publicTransport : public Transport{
public:
    publicTransport(string name, int capacity);
    void move(Building from, Building to) override;
};

#endif // PUBLICTRANSPORT_H

