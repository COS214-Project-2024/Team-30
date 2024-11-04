#ifndef TRAIN_H
#define TRAIN_H

#include "PublicTransport.h"
#include "trafficCommand.h"
#include <memory>

using namespace std;

class Train : public publicTransport {
private:
    shared_ptr<trafficCommand> trafficCmd; // Command to control traffic lights
public:
    Train(string name, int capacity, shared_ptr<Building> from, shared_ptr<trafficCommand> cmd);
    void Travel(shared_ptr<Building> to) override;
};

#endif // TRAIN_H
