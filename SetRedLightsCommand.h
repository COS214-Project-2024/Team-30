#ifndef SETREDLIGHTSCOMMAND_H
#define SETREDLIGHTSCOMMAND_H

#include "trafficCommand.h"
#include "Area.h"

using namespace std;

/**
 * @brief Command to set all traffic lights in an area to red.
 *
 * The SetRedLightsCommand class is responsible for executing the command
 * to change all traffic lights in a specified area to red for a specific
 * duration and then reset them to their original state.
 */
class SetRedLightsCommand : public trafficCommand {
private:
    shared_ptr<Area> area; ///< The area where the traffic lights will be affected.

public:
    /**
     * @brief Constructs a SetRedLightsCommand with the specified area.
     *
     * @param area Pointer to the area whose traffic lights are to be changed.
     */
    SetRedLightsCommand(shared_ptr<Area> area) : area(area) {}

    /**
     * @brief Executes the command to set all traffic lights to red.
     *
     * This method sets all lights in the area to red, waits for a duration,
     * and then resets them to their original state.
     */
    void execute() override;
};

#endif // SETREDLIGHTSCOMMAND_H
