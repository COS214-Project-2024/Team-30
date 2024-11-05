#ifndef TRAFFICCOMMAND_H
#define TRAFFICCOMMAND_H

#include <list>
#include "TrafficLight.h"
#include "Area.h"

/**
 * @brief Abstract base class for traffic commands.
 *
 * The trafficCommand class defines the interface for various traffic commands
 * that can be executed to control traffic lights and manage areas.
 */
class trafficCommand {
public:
    /**
     * @brief Virtual destructor for trafficCommand.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~trafficCommand() = default;

    /**
     * @brief Pure virtual method to execute a traffic command.
     *
     * This method must be implemented by derived classes to define
     * specific traffic command behaviors.
     */
    virtual void execute() = 0;
};

#endif // TRAFFICCOMMAND_H
