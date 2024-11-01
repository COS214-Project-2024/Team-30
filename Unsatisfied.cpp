#include "Satisfied.h"
#include "Unsatisfied.h"
#include "Citizen.h"

// void Unsatisfied::react() const
// {
// }
// void Unsatisfied::adjustHappiness(Citizen &citizen)
// {
// }

void Unsatisfied::changeState(Citizen &citizen)
{
    if (citizen.getHappinessMeter() < 50)
    {
        citizen.setEmotionalState(make_unique<Satisfied>());
    }
}
string Unsatisfied::getEmotionalState()
{
    return "Unsatisfied";
}