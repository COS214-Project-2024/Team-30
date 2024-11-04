#ifndef UTILITIES_H
#define UTILITIES_H

#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"
#include "Building.h"

#include <memory>
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
     * @param c The coal source for electricity generation.
     * @param w The water source for water supply.
     */
    Utilities(Building* b, Coal* c, Water* w);

private:
    unique_ptr<PowerPlant> powerPlant;         /**< PowerPlant instance responsible for electricity generation. */
    unique_ptr<SewageSystem> sewageSystem;     /**< SewageSystem instance responsible for waste disposal and treatment. */
    unique_ptr<WasteManagement> wasteManagement; /**< WasteManagement instance handling waste removal and recycling. */
    unique_ptr<WaterSupply> waterSupply;       /**< WaterSupply instance responsible for water distribution. */
    bool working;                              /**< Status of all utility systems. */
};

#endif // UTILITIES_H