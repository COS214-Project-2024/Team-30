#include "Infrastructure.h"
#include <iostream>

using namespace std;

void Infrastructure::update(Government* g)
{
     cout << "\n=================================================================" << endl;
     cout << "                      Infrastructure" << endl;
     cout << "=================================================================" << endl;

     cout << "Infrastructure is expanding, due to the increased populations. " << endl;

     cout << "=================================================================" << endl;
     g->increaseInfurstructure();
     // g->getInfrastructure();
}
