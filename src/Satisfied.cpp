#include "Satisfied.h"
#include "Unsatisfied.h"
#include "CitizensUnitTests/Citizen.h"



/**
 * @brief Changes the emotional state of the given citizen to Unsatisfied 
 *        if their happiness meter falls below 50.
 *
 * This method checks the happiness meter of the specified citizen. 
 * If the meter is less than 50, the citizen's emotional state is changed 
 * to Unsatisfied.
 *
 * @param citizen A reference to the Citizen object whose emotional state 
 *                is being modified.
 */
void Satisfied::changeState(Citizen &citizen)
{
    if (citizen.getHappinessMeter() < 50)
    {
        citizen.setEmotionalState(make_unique<Unsatisfied>());
    }
}
/**
 * @brief Retrieves the emotional state of the Satisfied object.
 *
 * This method returns a string representing the current emotional state 
 * of the Satisfied object.
 *
 * @return A string indicating the emotional state, which is "Satisfied".
 */
string Satisfied::getCurrentEmotion()
{
    return "Satisfied";
}