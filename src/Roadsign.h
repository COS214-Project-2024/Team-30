#ifndef ROADSIGN_H
#define ROADSIGN_H

#include "Sign.h"

using namespace std;

class RoadSign : public Sign {
public:
    RoadSign(string message, string type);
};

#endif // ROADSIGN_H
