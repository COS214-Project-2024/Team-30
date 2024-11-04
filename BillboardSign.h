#ifndef BILLBOARDSIGN_H
#define BILLBOARDSIGN_H

#include "Sign.h"

using namespace std;

/**
 * @class BillboardSign
 * @brief Represents a billboard sign that inherits from the Sign class.
 *
 */
class BillboardSign : public Sign {
public:
    /**
     * @brief Constructs a BillboardSign with a specified message
     * @param message The message to be displayed on the billboard sign
     */
    BillboardSign(const string& message) : Sign(message) {
        type = "BillBoardSign"; ///< Sets the type of sign to "BillBoardSign"
    }
};

#endif // BILLBOARDSIGN_H

