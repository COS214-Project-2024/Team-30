#include "PopulationGrowth.h"

void PopulationGrowth::update(Government *g)
{
    bR=(g->getPopulationNum() - oldPop);
    bR /= g->getPopulationNum();
    bR*=1000;
    printInfo(g);
    oldPop = g->getPopulationNum();
}

void PopulationGrowth::printInfo(Government* g)
{
    std::cout << "=================================================================" << std::endl;
    std::cout << "          Population Information               " << std::endl;
    std::cout << "=================================================================" << std::endl;
    std::cout << " Birth Rate           : " <<  bR << " births per 1,000 people"<<std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " Old Population       : " << oldPop << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << " New Population       : " << g->getPopulationNum() << std::endl;
    std::cout << "=================================================================" << std::endl;
}