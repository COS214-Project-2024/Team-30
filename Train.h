#ifndef TRAIN_H
#define TRAIN_H

#include "Transport.h"

using namespace std;

class Train : public Transport {
public:
    Train(string name, int capacity);
    void move(Building from, Building to) override;
};

#endif // TRAIN_H

