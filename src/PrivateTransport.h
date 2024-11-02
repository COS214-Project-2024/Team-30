#ifndef PRIVATETRANSPORT_H
#define PRIVATETRANSPORT_H

#include "Transport.h"

using namespace std;

class privateTransport : public Transport {
public:
    privateTransport(string name, int capacity);
    void move(Building from, Building to) override;
};

#endif // PRIVATETRANSPORT_H

