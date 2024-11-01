#include "Fires.h"

#include <random>

/**
 * @brief Calculates and applies fire damage to a specified building.
 *
 * This function simulates a fire by randomly determining its severity 
 * (mild, moderate, or severe) and calculating the corresponding damage. 
 * It then applies the calculated damage to the specified building and notifies 
 * the citizens within that building of the emergency.
 *
 * @param buildingType A shared pointer to the Building object that will 
 *                     take damage from the fire.
 */
void Fires::accessDamage(shared_ptr<Building> buildingType) {
    random_device rd; // Seed
    mt19937 gen(rd()); // Random number generator

    // Define the severity ranges
    int fireDamage = 0;
    int severity = gen() % 3; // Randomly choose between 0 (mild), 1 (moderate), or 2 (severe)

    if (severity == 0) {
        uniform_int_distribution<> dist(0, 15); // Mild fire damage range
        fireDamage = dist(gen);
        std::cout << "Mild fire! Inflicting " << fireDamage << " damage." << std::endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(16, 35); // Moderate fire damage range
        fireDamage = dist(gen);
        std::cout << "Moderate fire! Inflicting " << fireDamage << " damage." << std::endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(36, 50); // Severe fire damage range
        fireDamage = dist(gen);
        std::cout << "Severe fire! Inflicting " << fireDamage << " damage." << std::endl;
    }
    
    damage = fireDamage;

    // Apply the calculated damage to the building
    buildingType->takeDamage(fireDamage);
    buildingType->notifyCitizensOfEmergency(fireDamage);

}

/**
 * @brief Retrieves the type of emergency represented by the Fires class.
 *
 * @return std::string A string indicating the type of emergency, which 
 *                     is "Fire" in this case.
 */
string Fires::getTypeOfEmergency()
{
    return "Fire";
}

