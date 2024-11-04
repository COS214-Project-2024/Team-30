#ifndef TRAIN_H
#define TRAIN_H

#include "PublicTransport.h"
#include "trafficCommand.h"
#include <memory>

using namespace std;

/**
 * @class Train
 * @brief A class representing a train that inherits from publicTransport.
 *
 * The Train class adds functionality for controlling traffic lights through
 * a traffic command when traveling to a destination.
 */
class Train : public publicTransport {
private:
    shared_ptr<trafficCommand> trafficCmd; ///< Command to control traffic lights

public:
    /**
     * @brief Constructs a Train object with a specified name, capacity, and starting building.
     *
     * @param name The name of the train.
     * @param capacity The maximum capacity of passengers the train can carry.
     * @param from A shared pointer to the building from which the train departs.
     * @param cmd A shared pointer to a trafficCommand that controls traffic lights during travel.
     */
    Train(string name, int capacity, shared_ptr<Building> from, shared_ptr<trafficCommand> cmd);

    /**
     * @brief Travels from the current building to the specified destination building.
     *
     * Executes the associated traffic command to set all traffic lights to red
     * before transporting passengers to the destination building.
     *
     * @param to A shared pointer to the building to which the train will travel.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // TRAIN_H
