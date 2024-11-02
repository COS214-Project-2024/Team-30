#ifndef PLANE_H
#define PLANE_H

#include "Transport.h"

using namespace std;

class Plane : public Transport {
public:
    Plane(string name, int capacity);
    void move(Building from, Building to) override;
};

#endif // PLANE_H

