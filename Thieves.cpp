#include "Thieves.h"

#include <random>

void Thieves::accessDamage(shared_ptr<Building> buildingType) {
    // Set up random number generation
    random_device rd; // Seed
    mt19937 gen(rd()); // Random number generator

    // Define the severity ranges
    int theftDamage = 0;
    int severity = gen() % 3; // Randomly choose between 0 (minor), 1 (moderate), or 2 (major)

    if (severity == 0) {
        uniform_int_distribution<> dist(0, 5); // Minor theft damage range
        theftDamage = dist(gen);
        cout << "Minor theft incident! Inflicting " << theftDamage << " damage." << endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(6, 10); // Moderate theft damage range
        theftDamage = dist(gen);
        cout << "Moderate theft incident! Inflicting " << theftDamage << " damage." << endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(11, 20); // Major theft damage range
        theftDamage = dist(gen);
        cout << "Major theft incident! Inflicting " << theftDamage << " damage." << endl;
    }

    // Apply the calculated damage to the building
    buildingType->takeDamage(theftDamage);
    buildingType->notifyCitizensOfEmergency(theftDamage);
}

string Thieves::getTypeOfEmergency()
{
    return "string";
}
