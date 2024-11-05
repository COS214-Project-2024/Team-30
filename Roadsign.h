#ifndef ROADSIGN_H
#define ROADSIGN_H

#include "Sign.h"

using namespace std;

/**
 * @brief Represents a road sign in the traffic system.
 *
 * The RoadSign class inherits from the Sign class and represents a sign specifically
 * designed for roads, providing information or instructions to drivers.
 */
class RoadSign : public Sign {
public:
    /**
     * @brief Constructs a RoadSign object with a specified message.
     *
     * @param message The message displayed on the road sign.
     */
    RoadSign(const string& message) : Sign(message) {
        type = "RoadSign"; ///< Sets the type of sign to "RoadSign".
    }
};

#endif // ROADSIGN_H
