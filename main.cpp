/**
 * @file main.cpp
 * @brief Main application file for testing various components of the transportation simulation system.
 *
 * This file tests the functionality of signs, traffic lights, citizens, buildings, roads, and transport systems.
 * It creates instances of these components and demonstrates their behavior through various operations.
 */

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

using namespace std;

int main() {
    // Create and test different types of signs
    Sign mySign("This is my generic sign");
    BillboardSign myBill("This is my billboard");
    RoadSign myRoadSign("This is my roadsign");

    cout << "Testing my signs: " << endl;
    cout << "Sign " << mySign.getID() << " says " << mySign.getMessage() << " is of type " << mySign.getType() << endl;
    cout << "Sign " << myBill.getID() << " says " << myBill.getMessage() << " is of type " << myBill.getType() << endl;
    cout << "Sign " << myRoadSign.getID() << " says " << myRoadSign.getMessage() << " is of type " << myRoadSign.getType() << endl;
    cout << "Signs complete\n===========================================================================================\n";

    // Create and test a traffic light
    unique_ptr<TrafficLight> myTrafficLight = make_unique<TrafficLight>();
    cout << "Testing traffic lights:\n";
    cout << myTrafficLight->getID() << " state: " << myTrafficLight->getState() << endl;
    myTrafficLight->changeState();
    cout << myTrafficLight->getID() << " new state: " << myTrafficLight->getState() << endl;
    myTrafficLight->changeState();
    cout << myTrafficLight->getID() << " newest state: " << myTrafficLight->getState() << endl;
    myTrafficLight->changeState();
    cout << "TrafficLightsComplete\n===========================================================================================\n";

    // Create citizens and display the latest citizen ID
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

    // Create buildings and add citizens to a building
    shared_ptr<Building> b1 = make_shared<Building>(100, "Building 1");
    shared_ptr<Building> b2 = make_shared<Building>(100, "Building 2");
    shared_ptr<Building> b3 = make_shared<Building>(100, "Building 3");

    b1->addCitizen(c1);
    b1->addCitizen(c2);
    b1->addCitizen(c3);
    b1->addCitizen(c4);
    b1->addCitizen(c5);
    b1->addCitizen(c6);
    b1->addCitizen(c7);
    b1->addCitizen(c8);

    b1->printResidents();
    cout << "My testing for my basic buildings is done\n===========================================================================================\n";

    // Testing Road
    shared_ptr<Road> r1 = make_shared<Road>("myRoad");

    // Testing transport
    cout << "Testing transport\n";
    shared_ptr<privateTransport> transport1 = make_shared<privateTransport>("myTransport", 5, b1);
    transport1->addPeople(c1);
    transport1->addPeople(c2);
    transport1->addPeople(c3);
    transport1->addPeople(c4);
    transport1->addPeople(c5);
    transport1->addPeople(c6); // Does not add people when they are full
    transport1->printPassengers();
    b1->printResidents(); // Should be missing 1 through 5?

    transport1->Travel(b2);
    b2->printResidents();

    return 0;
}
