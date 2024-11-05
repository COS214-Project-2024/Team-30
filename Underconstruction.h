#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"

class Underconstruction : public BuildingState{

    private:
    protected:

    public:
    void handle() override;
    void changeState() override;
    string getStatus() override;
    unique_ptr<BuildingState> clone() const override;

};

#endif