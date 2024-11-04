#ifndef BILLBOARDSIGN_H
#define BILLBOARDSIGN_H

#include "Sign.h"

using namespace std;

class BillboardSign : public Sign {
public:
    BillboardSign(const string& message) : Sign(message)
    {
        type = "BillBoardSign";
    }
};

#endif
