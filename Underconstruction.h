#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"

class Underconstruction : public BuildingState{

    private:
    protected:

    public:
    void handle() override;
    void changeState() override;

};

#endif