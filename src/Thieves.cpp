#include "Thieves.h"
#include <random>

/**
 * @brief Calculates and applies theft damage to a specified building.
 *
 * This function simulates a theft incident by randomly determining its severity 
 * (minor, moderate, or major) and calculating the corresponding damage. 
 * It then applies the calculated damage to the specified building and notifies 
 * the citizens within that building of the emergency.
 *
 * @param buildingType A shared pointer to the Building object that will 
 *                     take damage from the theft.
 */
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
        std::cout << "Minor theft incident! Inflicting " << theftDamage << " damage." << std::endl;
    }
    else if (severity == 1) {
        uniform_int_distribution<> dist(6, 10); // Moderate theft damage range
        theftDamage = dist(gen);
        std::cout << "Moderate theft incident! Inflicting " << theftDamage << " damage." << std::endl;
    }
    else if (severity == 2) {
        uniform_int_distribution<> dist(11, 20); // Major theft damage range
        theftDamage = dist(gen);
        std::cout << "Major theft incident! Inflicting " << theftDamage << " damage." << std::endl;
    }

    // Apply the calculated damage to the building
    buildingType->takeDamage(theftDamage);
    buildingType->notifyCitizensOfEmergency(theftDamage);
}

/**
 * @brief Retrieves the type of emergency represented by the Thieves class.
 *
 * @return std::string A string indicating the type of emergency, which 
 *                     is "Theft" in this case.
 */
string Thieves::getTypeOfEmergency()
{
    return "Theft";
}
