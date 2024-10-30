#include <iostream>
#include "Housing.h"
#include "Infrastructure.h"
#include "Economy.h"
#include "Government.h"

int main() {

    Government cityGovernment;

    //  observers
    Housing housingObserver;
    Infrastructure infrastructureObserver;
    Economy economyObserver;

    // Attach 
    cityGovernment.attach(&housingObserver);
    cityGovernment.attach(&infrastructureObserver);
    cityGovernment.attach(&economyObserver);

    //population growth
    cityGovernment.populationGrowth(1000); 
    cityGovernment.populationGrowth(5000); 

    return 0;
}
