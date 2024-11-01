#include "Earthquake.h"
#include <random>
/**
 * @brief Calculates and applies earthquake damage to a specified building.
 *
 * This function simulates an earthquake by randomly determining its severity 
 * (mild, serious, or severe) and calculating the corresponding damage. It then 
 * applies the calculated damage to the specified building and notifies the 
 * citizens within that building of the emergency.
 *
 * @param buildingType A shared pointer to the Building object that will 
 *                     take damage from the earthquake.
 */
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
        std::cout << "Mild earthquake! Inflicting " << quakeDamage << " damage." << std::endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(26, 60); // Serious damage range
        quakeDamage = dist(gen);
        std::cout << "Serious earthquake! Inflicting " << quakeDamage << " damage." << std::endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(61, 100); // Severe damage range
        quakeDamage = dist(gen);
        std::cout << "Severe earthquake! Inflicting " << quakeDamage << " damage." << std::endl;
    }
    
    damage = quakeDamage;

    // Apply the calculated damage to the building
    buildingType->takeDamage(quakeDamage);
    buildingType->notifyCitizensOfEmergency(quakeDamage);
}

/**
 * @brief Retrieves the type of emergency represented by the Earthquake class.
 *
 * @return std::string A string indicating the type of emergency, which 
 *                     is "Earthquake" in this case.
 */
string Earthquake::getTypeOfEmergency()
{
    return "Earthquake";
}

