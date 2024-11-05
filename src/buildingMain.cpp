// #include <iostream>
// #include <memory> // Include for smart pointers
// #include "Building.h"
// #include "ResidentialFactory.h"
// #include "CommercialFactory.h"
// #include "IndustrialFactory.h"
// #include "LandmarkFactory.h"
// #include "Underconstruction.h"
// #include "Built.h"
// #include "Destroyed.h"

// using namespace std;
// int main() {
//     // Create factories
//     ResidentialFactory residentialFactory;
//     CommercialFactory commercialFactory;
//     IndustrialFactory industrialFactory;
//     LandmarkFactory landmarkFactory;

//     // Create buildings using factories with smart pointers
//     unique_ptr<Building> residentialBuilding = residentialFactory.createBuilding();
//     unique_ptr<Building> commercialBuilding = commercialFactory.createBuilding();
//     unique_ptr<Building> industrialBuilding = industrialFactory.createBuilding();
//     unique_ptr<Building> landmarkBuilding = landmarkFactory.createBuilding();

//     residentialBuilding->displayInfo();
//     commercialBuilding->displayInfo();
//     industrialBuilding->displayInfo();
//     landmarkBuilding->displayInfo();

//     cout << "\n\n\n" << "PROTOTYPE" << "\n\n\n";

//     unique_ptr<Building> residentialBuilding2 = residentialBuilding->clone();
//     residentialBuilding2->setState(make_unique<Built>());
//     residentialBuilding2->displayInfo();
//     cout << "\n\n";
//     residentialBuilding->displayInfo();


//     return 0;
// }
