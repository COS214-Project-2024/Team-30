#ifndef CITIZEN_H
#define CITIZEN_H

#include "TaxBracket.h"
#include "EmploymentStatus.h"
#include "EmotionalState.h"
#include "Satisfied.h"
#include "Unsatisfied.h"
#include "OfficeJob.h"
#include "IndustrialJob.h"
#include "Unemployed.h"
#include "LowestTaxBracket.h"
#include "MiddleTaxBracket.h"
#include "HighestTaxBracket.h"

#include <iostream>
#include <string>
#include <memory>
#include <random>
using namespace std;

class Building;

class Citizen : public std::enable_shared_from_this<Citizen>
{
private:
    int id;
    int income;
    int accountBalance;
    int happinessMeter;
    unique_ptr<TaxBracket> taxBracket;
    unique_ptr<EmploymentStatus> employmentStatus;
    unique_ptr<EmotionalState> emotionalState;
    shared_ptr<Building> home;
    shared_ptr<Building> currentBuilding;
    static int nextID;

public:
    /**
     * @brief Constructs a Citizen object with initial randomized attributes.
     *
     * Initializes the Citizen with a unique ID, a zero account balance,
     * randomly assigned employment status, tax bracket, and emotional state.
     * Additionally, assigns an initial happiness level and calls functions
     * to set income and adjust account balance.
     */
    Citizen();
    /**
     * @brief Calculates and deducts the Citizen's tax payment from their income.
     *
     * This method determines the amount of tax the Citizen should pay based on
     * their current tax bracket and income. If the tax amount exceeds their
     * income, it deducts the remaining income instead. The tax amount is then
     * returned, which can be added to the city budget.
     *
     * @return int The actual tax amount paid, capped at the Citizen's income
     * if they cannot cover the full tax amount.
     */
    int payTax();
    /**
     * @brief Retrieves the employment status of the Citizen as a string.
     *
     * @return std::string The Citizen's current employment status.
     */
    string getEmploymentStatus();
    /**
     * @brief Deducts the Citizen's tax payment from their account balance.
     *
     * This method calculates the amount to pay in taxes based on the Citizen's
     * income and current tax bracket, then deducts this amount from their
     * account balance.
     */
    void payTaxes();
    /**
     * @brief Adds the Citizen's income to their account balance.
     *
     * This method increments the account balance by the income amount if citizen is employed. Otherwise, citizen cannot be paid hence happiness decreases by a single unit
     */
    void getPaid();
    /**
     * @brief Retrieves the current account balance of the Citizen.
     * @return int The Citizen's account balance.
     */
    int getAccountBalance();
    /**
     * @brief Assigns the Citizen to a specified building.
     *
     * This function assigns the Citizen to a building, represented by a shared pointer.
     * If a valid building pointer is provided, the Citizen is added to the building's
     * list of occupants.
     *
     * @param building A shared pointer to the Building object.
     */
    void assignToBuilding(shared_ptr<Building> building);
    /**
     * @brief Sets the home for the citizen.
     *
     * This method assigns a shared pointer to a `Building` object as the citizen's home.
     * The ownership of the building is shared, allowing multiple `Citizen` instances or other
     * entities to reference the same building.
     *
     * @param building A `std::shared_ptr` to a `Building` object representing the home of the citizen.
     */
    void setHome(std::shared_ptr<Building> home);
    /**
     * @brief Adjusts the Citizen's happiness in response to an emergency event.
     *
     * The function decreases the Citizen's happiness meter based on the severity
     * of the damage. Minor, medium, and severe damages cause progressively greater
     * happiness reductions, capped at a minimum of 0. After updating the happiness meter,
     * the function checks for an emotional state change.
     *
     * @param damage An integer representing the severity of the emergency damage.
     */
    void reactToEmergency(int damage);
    /**
     * @brief Retrieves the current happiness level of the Citizen.
     * @return int The Citizen's happiness level.
     */
    int getHappinessMeter();
    /**
     * @brief Retrieves the Citizen's unique ID.
     * @return int The unique ID of the Citizen.
     */
    int getID() const;
    /**
     * @brief Retrieves the Citizen's income.
     * @return int The Citizen's income amount.
     */
    int getIncome();
    /**
     * @brief Retrieves the citizen's home.
     *
     * This function returns a shared pointer to the `Building` instance representing the citizen's home.
     * The home is shared, so multiple entities can hold references to it.
     *
     * @return std::shared_ptr<Building> A shared pointer to the Building instance representing the citizen's home.
     */
    shared_ptr<Building> getHome();
    /**
     * @brief Retrieves the emotional state of the Citizen as a string.
     *
     * @return std::string The Citizen's current emotional state.
     */
    string getEmotionalState();
    /**
     * @brief Sets the Citizen's emotional state.
     *
     * Assigns a new emotional state to the Citizen, using move semantics
     * to transfer ownership.
     *
     * @param emotionalState A unique pointer to the new EmotionalState.
     */
    void setEmotionalState(unique_ptr<EmotionalState> emotionalState);
    /**
     * @brief Sets a new employment status for the Citizen.
     *
     * This function changes the Citizen's employment status to a new value
     * using move semantics to transfer ownership of the EmploymentStatus unique pointer.
     *
     * @param status A unique pointer to the new EmploymentStatus object.
     */
    void setEmploymentStatus(std::unique_ptr<EmploymentStatus> status);
    /**
     * @brief Prints the details of the Citizen in a formatted output.
     *
     * Displays the Citizen's ID, employment status, income, emotional state,
     * tax bracket, account balance, and happiness meter with a stylized border
     * for clarity.
     */
    void printDetails(); // helper to see that constructor works as expected
    /**
     * @brief Adjusts the Citizen's happiness in response to paying taxes.
     *
     * If the Citizen is unemployed, a higher penalty is applied to the happiness meter
     * than for employed citizens. Happiness is capped at a minimum of 0, and if necessary,
     * an emotional state change is triggered.
     */
    void respondToTax();
    /**
     * @brief Adjusts the Citizen's happiness in response to receiving a payment.
     *
     * Increases the Citizen's happiness meter by 20, capping it at a maximum of 100.
     * If necessary, this triggers an emotional state change based on the new happiness level.
     */
    void respondToPayment();
    /**
     * @brief Adjusts the Citizen's emotional response when not hired.
     *
     * This function is triggered when the Citizen does not get hired,
     * reducing their happiness by a fixed amount. It then updates
     * the Citizen's emotional state based on the new happiness level.
     *
     * @note The happiness meter is reduced by 5 points, and the emotional state
     *       is updated by calling the changeState() method on the current state.
     */
    void reactToNotGettingHired();
    /**
     * @brief Adjusts the Citizen's happiness based on a change in employment status.
     *
     * If the Citizen gained a job, their happiness meter increases; if they lost
     * a job, it decreases. The happiness level is then clamped within a range
     * of 0 to 100. If necessary, an emotional state change is triggered.
     *
     * @param gainedJob A boolean indicating whether the Citizen gained (true)
     * or lost (false) a job.
     */
    void respondToJobChange(bool gainedJob);
    /**
     * @brief Increases the Citizen's happiness in response to improved infrastructure.
     *
     * Adds a small boost to the Citizen's happiness meter, capping it at 100.
     * If the happiness change warrants it, triggers a change in the Citizen's
     * emotional state.
     */
    void respondToIncreasedInfrastructure();
    /**
     * @brief Updates the Citizen's employment status when they are hired.
     *
     * If the Citizen is currently unemployed, assigns the new job and updates
     * the happiness meter accordingly, capping it at 100. Prints a message
     * indicating the Citizen's new employment status.
     *
     * @param newJob A unique pointer to the new EmploymentStatus object.
     */
    void getHired(std::unique_ptr<EmploymentStatus> newJob);
    /**
     * @brief Transitions the Citizen to an unemployed status when they are fired.
     *
     * If the Citizen is currently employed, this function resets their employment status
     * to Unemployed and decreases their happiness meter by 20, ensuring it does not fall below 0.
     * Prints a message indicating the Citizen has been fired.
     */
    void getFired();
    /**
     * @brief Sets the happiness level for a Citizen.
     *
     * This function updates the Citizen's happiness meter with a specified integer value.
     *
     * @param happiness The new happiness level to set for the Citizen.
     */
    void setHappinessMeter(int happinessMeter);

    void reactToUtilities(bool utilitiesActive);
};
#endif