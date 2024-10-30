#include "Satisfied.h"
#include "Unsatisfied.h"
#include "Citizen.h"

// void Satisfied::react() const
// {
// }
// void Satisfied::adjustHappiness(Citizen &citizen)
// {
    
// }
void Satisfied::changeState(Citizen &citizen)
{
    if (citizen.getHappinessMeter() < 50)
    {
        citizen.setEmotionalState(make_unique<Unsatisfied>());
    }
}
string Satisfied::getEmotionalState()
{
    return "Satisfied";
}