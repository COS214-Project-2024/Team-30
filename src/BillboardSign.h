#ifndef BILLBOARDSIGN_H
#define BILLBOARDSIGN_H

#include "Sign.h"

using namespace std;

class BillboardSign : public Sign {
public:
    BillboardSign(string message, string type);
};

#endif // BILLBOARDSIGN_H
