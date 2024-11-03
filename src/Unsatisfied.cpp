#include "Satisfied.h"
#include "Unsatisfied.h"
#include "Citizen.h"

/**
 * @brief Changes the emotional state of the given citizen to Satisfied 
 *        if their happiness meter is 50 or above.
 *
 * This method checks the happiness meter of the specified citizen. 
 * If the meter is equal to or greater than 50, the citizen's emotional 
 * state is changed to Satisfied.
 *
 * @param citizen A reference to the Citizen object whose emotional state 
 *                is being modified.
 */
void Unsatisfied::changeState(Citizen &citizen)
{
    if (citizen.getHappinessMeter() >= 50)
    {
        citizen.setEmotionalState(make_unique<Satisfied>());
    }
}
/**
 * @brief Retrieves the emotional state of the Unsatisfied object.
 *
 * This method returns a string representing the current emotional state 
 * of the Unsatisfied object.
 *
 * @return A string indicating the emotional state, which is "Unsatisfied".
 */
string Unsatisfied::getCurrentEmotion()
{
    return "Unsatisfied";
}