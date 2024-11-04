#include "PopulationGrowth.h"

using namespace std;
/**
 * @brief Updates the observer with the current population data.
 *
 * This method calculates the birth rate based on the difference between the
 * current population and the previous population, then calls printInfo to 
 * display the updated information. The old population value is updated 
 * after the calculation.
 *
 * @param g A pointer to a Government object containing the updated population information.
 */
void PopulationGrowth::update(Government *g)
{
    // std::cout<<oldPop<<"\n";
    bR = (g->getPopulationNum() - oldPop); // Calculate the change in population
    bR /= g->getPopulationNum(); // Calculate the birth rate
    bR *= 50; // Convert to births per 1,000 people
    printInfo(g); // Print the current population information
    oldPop = g->getPopulationNum(); // Update the old population for the next call
}

/**
 * @brief Prints information about the government's population.
 *
 * This method outputs the current birth rate, old population, and new population
 * of the specified government to the console in a formatted manner.
 *
 * @param g A pointer to a Government object whose information is to be printed.
 */
void PopulationGrowth::printInfo(Government* g)
{
    cout << "\n=================================================================" << endl;
    cout << "          Population Information               " << endl;
    cout << "=================================================================" << endl;
    cout << " Birth Rate           : " <<  bR << " births per 50 people" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << " Old Population       : " << oldPop << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << " New Population       : " << g->getPopulationNum() << endl;
    cout << "=================================================================" << endl;
}


// #include "PopulationGrowth.h"

// void PopulationGrowth::update(Government *g)
// {
//     bR=(g->getPopulationNum() - oldPop);
//     bR /= g->getPopulationNum();
//     bR*=1000;
//     printInfo(g);
//     oldPop = g->getPopulationNum();
// }

// void PopulationGrowth::printInfo(Government* g)
// {
//     std::cout << "=================================================================" << std::endl;
//     std::cout << "          Population Information               " << std::endl;
//     std::cout << "=================================================================" << std::endl;
//     std::cout << " Birth Rate           : " <<  bR << " births per 1,000 people"<<std::endl;
//     std::cout << "-----------------------------------------------------------------" << std::endl;
//     std::cout << " Old Population       : " << oldPop << std::endl;
//     std::cout << "-----------------------------------------------------------------" << std::endl;
//     std::cout << " New Population       : " << g->getPopulationNum() << std::endl;
//     std::cout << "=================================================================" << std::endl;
// }