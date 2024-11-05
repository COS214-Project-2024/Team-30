#include "Housing.h"
#include <iostream>

using namespace std;

void Housing::update(Government* g)
{
    cout << "\n=================================================================" << endl;
    cout<<  "                 Review on Housing Needs\n";
    cout << "=================================================================" << endl;
    int ResCap =g->ResidentialCapacity();
    if(ResCap<g->getPopulationNum()){
        cout<<"The current capacity of Residential buildings is "<<ResCap<<" .\n";
        cout<<"Please consider building new Residential buildings to support the current growth in population.\n\n";
    }else{
        cout<<"Current Residential Capacity: "<<ResCap<<"\n";
        cout<<"The current Residential capacity is sufficient.\n";
    }
    cout << "=================================================================" << endl;

}
