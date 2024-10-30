#ifndef BUILT_H
#define BUILT_H

#include "BuildingState.h"

class Built : public BuildingState{

    private:
    protected:
    public:
    void handle() override;
    void changeState() override;
};

#endif