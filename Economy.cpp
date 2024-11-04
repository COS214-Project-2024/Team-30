#include "Economy.h"
#include <iostream>

using namespace std;
/**
 * @brief Updates the economic state based on the Government's current population and employment data.
 *
 * This implementation displays a message indicating that the economy is adapting to support the 
 * current population. It then calls `calculateEmploymentRate` on the `Government` object to 
 * adjust the employment rate, reflecting the current state of the economy. Finally, it outputs 
 * revised city information.
 *
 * @param g Pointer to the `Government` object that provides the current economic and population data.
 */
void Economy::update(Government* g)
{
    cout << "\n=================================================================" << endl;
    cout << "                      Economic State                                    " << endl;
    cout << "=================================================================" << endl;
    cout << "Economy has grown to support population: " << g->getPopulationNum() << endl;
     cout << "=================================================================" << endl;
    g->calculateEmploymentRate();
     cout << "\n=================================================================" << endl;
    cout << "\nRevised information on city" << endl;
    g->printInfo();
}