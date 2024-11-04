#ifndef PLANE_H
#define PLANE_H

#include "PublicTransport.h"

using namespace std;

class Plane : public publicTransport {
public:
    Plane(string name, int capacity);
    void Travel(shared_ptr<Building> to) override;
};

#endif // PLANE_H

