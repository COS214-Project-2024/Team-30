#ifndef ROADSIGN_H
#define ROADSIGN_H

#include "Sign.h"

using namespace std;

/**
 * @brief Represents a road sign in the traffic system.
 *
 * Implaments the template design pattern, and gives road sign functionality to drivers
 */
class RoadSign : public Sign {
public:
    /**
     * @brief Constructs a RoadSign object with a specified message.
     *
     * @param message The message displayed 
     */
    RoadSign(const string& message) : Sign(message) {
        type = "RoadSign"; ///< Sets type
    }
};

#endif // ROADSIGN_H
