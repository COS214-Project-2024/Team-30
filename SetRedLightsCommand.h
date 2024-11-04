#ifndef ASSIGNMENT_SETREDLIGHTSCOMMAND_H
#define ASSIGNMENT_SETREDLIGHTSCOMMAND_H

#include "trafficCommand.h"
#include <memory>
#include "Area.h"

class SetRedLightsCommand : public trafficCommand {
private:
    shared_ptr<Area> area;
public:
    SetRedLightsCommand(const shared_ptr<Area>& area) : area(area) {}
    void execute() override;
};

#endif //ASSIGNMENT_SETREDLIGHTSCOMMAND_H
