#ifndef UTILITIES_H
#define UTILITIES_H

#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"

#include "Building.h"

#include <string>

using namespace std;

/**
 * @class Utilities
 * @brief Manages all utility services for a specific building, ensuring essential services are operational.
 */
class Utilities {
public:
    /**
     * @brief Constructs a Utilities manager for a given building.
     * @param b The building that requires utility services.
     */
    Utilities(Building* b);

private:
    PowerPlant* powerPlant;         /**< PowerPlant instance responsible for electricity generation. */
    SewageSystem* sewageSystem;     /**< SewageSystem instance responsible for waste disposal and treatment. */
    WasteManagement* wasteManagement; /**< WasteManagement instance handling waste removal and recycling. */
    WaterSupply* waterSupply;       /**< WaterSupply instance responsible for water distribution. */
    bool working;
};

#endif // UTILITIES_H