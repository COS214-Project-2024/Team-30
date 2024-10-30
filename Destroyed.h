#ifndef DESTROYED_H
#define DESTROYED_H

#include "BuildingState.h"

class Destroyed : public BuildingState{

    private:
    protected:
    public:
    void handle() override;
    void changeState() override;
    string getStatus() override;
};

#endif