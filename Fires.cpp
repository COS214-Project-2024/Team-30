#include "Fires.h"

#include <random>

void Fires::accessDamage(shared_ptr<Building> buildingType) {
    random_device rd; // Seed
    mt19937 gen(rd()); // Random number generator

    // Define the severity ranges
    int fireDamage = 0;
    int severity = gen() % 3; // Randomly choose between 0 (mild), 1 (moderate), or 2 (severe)

    if (severity == 0) {
        uniform_int_distribution<> dist(0, 15); // Mild fire damage range
        fireDamage = dist(gen);
        cout << "Mild fire! Inflicting " << fireDamage << " damage." << endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(16, 35); // Moderate fire damage range
        fireDamage = dist(gen);
        cout << "Moderate fire! Inflicting " << fireDamage << " damage." << endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(36, 50); // Severe fire damage range
        fireDamage = dist(gen);
        cout << "Severe fire! Inflicting " << fireDamage << " damage." << endl;
    }
    damage = fireDamage;
    // Apply the calculated damage to the building
    buildingType->takeDamage(fireDamage);
    buildingType->notifyCitizensOfEmergency(fireDamage);

}

string Fires::getTypeOfEmergency()
{
    return "Fire";
}
