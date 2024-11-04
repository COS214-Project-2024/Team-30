#ifndef TAXI_H
#define TAXI_H

#include "Transport.h"

using namespace std;

class Taxi : public Transport {
public:
    Taxi(string name, int capacity);
    void Travel(shared_ptr<Building> to) override;
};

#endif // TAXI_H

