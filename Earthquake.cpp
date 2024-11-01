#include "Earthquake.h"
#include <random>

void Earthquake::accessDamage(shared_ptr<Building> buildingType) {
    // Set up random number generation
    random_device rd; // Seed
    mt19937 gen(rd()); // Random number generator

    // Define the severity ranges
    int quakeDamage = 0;
    int severity = gen() % 3; // Randomly choose between 0 (mild), 1 (serious), or 2 (severe)

    if (severity == 0) {
        uniform_int_distribution<> dist(0, 25); // Mild damage range
        quakeDamage = dist(gen);
        cout << "Mild earthquake! Inflicting " << quakeDamage << " damage." << endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(26, 60); // Serious damage range
        quakeDamage = dist(gen);
        cout << "Serious earthquake! Inflicting " << quakeDamage << " damage." << endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(61, 100); // Severe damage range
        quakeDamage = dist(gen);
        cout << "Severe earthquake! Inflicting " << quakeDamage << " damage." << endl;
    }
    damage = quakeDamage;
    // Apply the calculated damage to the building
    buildingType->takeDamage(quakeDamage);
    buildingType->notifyCitizensOfEmergency(quakeDamage);
}

string Earthquake::getTypeOfEmergency()
{
    return "Earthquake";
}
