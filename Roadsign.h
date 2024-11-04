#ifndef ROADSIGN_H
#define ROADSIGN_H

#include "Sign.h"

using namespace std;

class RoadSign : public Sign {
public:
    RoadSign(const string& message) : Sign(message)
    {
        type = "RoadSign";
    }
};

#endif // ROADSIGN_H