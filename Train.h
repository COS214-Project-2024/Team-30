#ifndef TRAIN_H
#define TRAIN_H

#include "PublicTransport.h"
#include "TrafficCommand.h"
#include <memory>

using namespace std;

/**
 * @class Train
 * @brief A class representing a train that inherits from publicTransport.
 *
 * The Train class adds functionality for controlling traffic lights through
 * a traffic command 
 */
class Train : public publicTransport {
private:
    shared_ptr<trafficCommand> trafficCmd; 

public:
    Train() : publicTransport(0,nullptr){}
    /**
     * @brief Constructs a Train object with a specified name, capacity, and starting building.
     *
     * @param name The name of the train.
     * @param capacity The maximum capacity of passengers the train can carry.
     * @param from A shared pointer to the building from which the train departs.
     * @param cmd A shared pointer to a trafficCommand that controls traffic lights during travel.
     */
    Train(int capacity, shared_ptr<Building> from, shared_ptr<trafficCommand> cmd);

    /**
     * @brief Travels from the current building to the specified destination building.
     *
     * Executes the traffic command to set the areas lights to red
     *
     * @param to A shared pointer to the building to which the train will travel.
     */
    void Travel(shared_ptr<Building> to) override;
};

#endif // TRAIN_H
