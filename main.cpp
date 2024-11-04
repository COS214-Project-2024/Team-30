#include <iostream>
#include "TrafficLight.h"
#include "Sign.h"
#include "Road.h"
#include "BillboardSign.h"
#include "Roadsign.h"
#include "Timer.h"
#include "Transport.h"
#include "Taxi.h"
#include "Train.h"
#include "Plane.h"
#include "PrivateTransport.h"

int main() {
    //my to do list: railway? ask for type checkers on buildings, navigation through the roads
    Sign mySign("This is my generic sign");
    BillboardSign myBill("This is my billboard");
    RoadSign myRoadSign("Thjis is my roadsign");
    cout << "Testing my signs: " << endl;
    cout << mySign.getID() << " says " << mySign.getMessage() << " is of type " << mySign.getType() << endl;
    cout << myBill.getID() << " says " << myBill.getMessage() << " is of type " << myBill.getType() << endl;
    cout << myRoadSign.getID() << " says " << myRoadSign.getMessage() << " is of type " << myRoadSign.getType() << endl;
    cout << "Signs complete\n===========================================================================================\n";

    unique_ptr<TrafficLight> myTrafficLight = make_unique<TrafficLight>();
    cout <<"Testing traffic lights:\n";
    cout << myTrafficLight->getID() << " state: " << myTrafficLight->getState() <<endl;
    myTrafficLight->changeState();
    cout << myTrafficLight->getID() << " new state: " << myTrafficLight->getState() <<endl;
    myTrafficLight->changeState();
    cout << myTrafficLight->getID() << " newest state: " << myTrafficLight->getState() <<endl;
    myTrafficLight->changeState();
    cout << "TrafficLightsComplete\n===========================================================================================\n";

    shared_ptr<Citizen> c1 = make_shared<Citizen>();
    shared_ptr<Citizen> c2 = make_shared<Citizen>();
    shared_ptr<Citizen> c3 = make_shared<Citizen>();
    shared_ptr<Citizen> c4 = make_shared<Citizen>();
    shared_ptr<Citizen> c5 = make_shared<Citizen>();
    shared_ptr<Citizen> c6 = make_shared<Citizen>();
    shared_ptr<Citizen> c7 = make_shared<Citizen>();
    shared_ptr<Citizen> c8 = make_shared<Citizen>();
    shared_ptr<Citizen> c9 = make_shared<Citizen>();
    shared_ptr<Citizen> c10 = make_shared<Citizen>();
    shared_ptr<Citizen> c11 = make_shared<Citizen>();

    cout << "latest citizen ID: " << c11->getID() << endl;
    cout << "Citizens working\n===========================================================================================\n";

    //buildings
    shared_ptr<Building> b1 = make_shared<Building>(100,"Building 1");
    shared_ptr<Building> b2 = make_shared<Building>(100,"Building 2");
    shared_ptr<Building> b3 = make_shared<Building>(100,"Building 3");

    b1->addCitizen(c1);
    b1->addCitizen(c2);
    b1->addCitizen(c3);
    b1->addCitizen(c4);
    b1->addCitizen(c5);
    b1->addCitizen(c6);
    b1->addCitizen(c7);
    b1->addCitizen(c8);

    b1->printResidents();
    cout << "My testiong for my basic buildings is done\n===========================================================================================\n";

    //testing Road
    shared_ptr<Road> r1 = make_shared<Road>("myRoad");

    //testing transport
    cout << "Testing transport\n";
    shared_ptr<privateTransport> transport1 = make_shared<privateTransport>("myTransport",5,b1);
    transport1->addPeople(c1);
    transport1->addPeople(c2);
    transport1->addPeople(c3);
    transport1->addPeople(c4);
    transport1->addPeople(c5);
    transport1->addPeople(c6); //does not add people when they are full
    transport1->printPassengers();
    b1->printResidents(); //should be missing 1 through 5?

    transport1->Travel(b2);
    b2->printResidents();
    return 0;
}
