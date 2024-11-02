#include "Citizen.h"
#include "Building.h"
#include <iomanip>
int Citizen::nextID = 1; // or 0, depending on your starting point for IDs

/**
 * @brief Constructs a Citizen object with initial randomized attributes.
 *
 * Initializes the Citizen with a unique ID, a zero account balance, 
 * randomly assigned employment status, tax bracket, and emotional state.
 * Additionally, assigns an initial happiness level and calls functions 
 * to set income and adjust account balance.
 */
Citizen::Citizen() : id(nextID++)
{
    accountBalance = 0;
    // Random number generator setup
    random_device rd;
    mt19937 gen(rd());

    // Step 1: Randomly assign EmploymentStatus
      /**
     * @brief Step 1: Randomly assign EmploymentStatus
     * 
     * Generates a random integer to assign one of three employment statuses 
     * (OfficeJob, IndustrialJob, or Unemployed) along with the associated 
     * tax bracket.
     */
    uniform_int_distribution<> employmentDist(0, 2);
    int employmentChoice = employmentDist(gen);

    switch (employmentChoice)
    {
    case 0:
        employmentStatus = make_unique<OfficeJob>();
        taxBracket = make_unique<HighestTaxBracket>();
        break;
    case 1:
        employmentStatus = make_unique<IndustrialJob>();
        taxBracket = make_unique<MiddleTaxBracket>();
        break;
    case 2:
        employmentStatus = make_unique<Unemployed>();
        taxBracket = make_unique<LowestTaxBracket>();
        break;
    }
     /**
     * @brief Step 2: Assign initial EmotionalState
     * 
     * Sets the emotional state to Satisfied initially.
     */
    emotionalState = make_unique<Satisfied>();

    // Step 3: Randomly assign initial happiness meter
    /**
     * @brief Step 3: Randomly assign initial happiness meter
     * 
     * Generates a random integer between 0 and 100 for the initial happiness level.
     */
    uniform_int_distribution<> happinessDist(0, 100); // Adjust the range as necessary
    happinessMeter = happinessDist(gen); // Assign a random happiness level

    emotionalState->changeState(*this);
    
    // Initialize other attributes
    income = employmentStatus->getIncome(); // Default income, modify if needed
    getPaid(); // Presumably fills account balance based on income
}
/**
 * @brief Adds the Citizen's income to their account balance.
 *
 * This method increments the account balance by the income amount.
 */
void Citizen::getPaid()
{
    accountBalance = accountBalance + income;
}
/**
 * @brief Retrieves the Citizen's unique ID.
 * @return int The unique ID of the Citizen.
 */
int Citizen::getID() const
{
    return id;
}
/**
 * @brief Retrieves the current happiness level of the Citizen.
 * @return int The Citizen's happiness level.
 */
int Citizen::getHappinessMeter()
{
    return happinessMeter;
}
/**
 * @brief Sets the Citizen's emotional state.
 *
 * Assigns a new emotional state to the Citizen, using move semantics 
 * to transfer ownership.
 *
 * @param emotionalState A unique pointer to the new EmotionalState.
 */
void Citizen::setEmotionalState(unique_ptr<EmotionalState> emotionalState)
{
    this->emotionalState = std::move(emotionalState);
}
/**
 * @brief Retrieves the Citizen's income.
 * @return int The Citizen's income amount.
 */
int Citizen::getIncome()
{
    return income;
}
/**
 * @brief Retrieves the current account balance of the Citizen.
 * @return int The Citizen's account balance.
 */
int Citizen::getAccountBalance()
{
    return this->accountBalance;
}

/**
 * @brief Deducts the Citizen's tax payment from their account balance.
 *
 * This method calculates the amount to pay in taxes based on the Citizen's 
 * income and current tax bracket, then deducts this amount from their 
 * account balance.
 */
void Citizen::payTaxes()
{
    accountBalance = accountBalance - taxBracket->getamountToPay(income);
}

/**
 * @brief Prints the details of the Citizen in a formatted output.
 *
 * Displays the Citizen's ID, employment status, income, emotional state, 
 * tax bracket, account balance, and happiness meter with a stylized border 
 * for clarity.
 */
void Citizen::printDetails()
{
    // Set a width for the labels
    int labelWidth = 20;

    // Calculate the length of the border based on the maximum line length
    std::string border(60, '.'); // Adjust the number (60) based on desired border length

    std::cout << border << std::endl;  // Print top border

    std::cout << std::setw(labelWidth) << std::left << "Person:" 
              << getID() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Employment Status:" 
              << employmentStatus->getJobType() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Income:" 
              << income << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Emotional State:" 
              << emotionalState->getCurrentEmotion() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Tax Bracket:" 
              << taxBracket->getTaxBracket() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Account Balance:" 
              << accountBalance << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Happiness Meter:" 
              << happinessMeter << std::endl;

    std::cout << border << std::endl;  // Print bottom border
}

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
int Citizen::payTax()
{
    // Get the current tax amount based on the Citizen's tax bracket
    int amount = taxBracket->getamountToPay(income);

    // Ensure the Citizen does not pay more than their available income
    if (amount > income)
    {
        amount = income; // If insufficient income, they pay only what they have
    }

    // Deduct the tax amount from the income
    income = income - amount;

    return amount; // Tax amount to be added to city budget
}


// this is for employment rate
/**
 * @brief Retrieves the employment status of the Citizen as a string.
 * 
 * @return std::string The Citizen's current employment status.
 */
string Citizen::getEmploymentStatus()
{
    return employmentStatus->getJobType();
}

/**
 * @brief Retrieves the emotional state of the Citizen as a string.
 * 
 * @return std::string The Citizen's current emotional state.
 */
string Citizen::getEmotionalState()
{
    return emotionalState->getCurrentEmotion();
}

/**
 * @brief Adjusts the Citizen's happiness in response to paying taxes.
 * 
 * If the Citizen is unemployed, a higher penalty is applied to the happiness meter 
 * than for employed citizens. Happiness is capped at a minimum of 0, and if necessary, 
 * an emotional state change is triggered.
 */
void Citizen::respondToTax()
{
    int penalty = (employmentStatus->getJobType() == "Unemployed") ? 15 : 10;
    happinessMeter -= penalty;                    // A tax penalty greater for unemployed citizens
    happinessMeter = std::max(happinessMeter, 0); // Ensure it doesn't go below 0
    emotionalState->changeState(*this);           // Trigger state change if necessary
}

/**
 * @brief Adjusts the Citizen's happiness in response to receiving a payment.
 * 
 * Increases the Citizen's happiness meter by 20, capping it at a maximum of 100. 
 * If necessary, this triggers an emotional state change based on the new happiness level.
 */
void Citizen::respondToPayment()
{
    happinessMeter += 20;                           // Increase happiness with payment
    happinessMeter = std::min(happinessMeter, 100); // Ensure it doesn't exceed 100
    emotionalState->changeState(*this);
}

/**
 * @brief Clamps a value within a specified range.
 *
 * Checks if the value is less than the minimum or greater than the maximum 
 * and returns the clamped value within this range.
 *
 * @param value The value to be clamped.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return int The clamped value within the specified range.
 */
int clamp(const int &value, const int &min, const int &max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

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
void Citizen::respondToJobChange(bool gainedJob)
{
    if (gainedJob)
    {
        happinessMeter += 20; // Significant boost for gaining employment
    }
    else
    {
        happinessMeter -= 20; // Significant drop for losing employment
    }
    happinessMeter = clamp(happinessMeter, 0, 100);
    emotionalState->changeState(*this);
}

/**
 * @brief Increases the Citizen's happiness in response to improved infrastructure.
 *
 * Adds a small boost to the Citizen's happiness meter, capping it at 100. 
 * If the happiness change warrants it, triggers a change in the Citizen's 
 * emotional state.
 */
void Citizen::respondToIncreasedInfrastructure()
{
    happinessMeter += 5;                           // Increase happiness with infrastructure improvements
    happinessMeter = std::min(happinessMeter, 100); // Ensure it doesn't exceed 100
    emotionalState->changeState(*this);
}

/**
 * @brief Updates the Citizen's employment status when they are hired.
 *
 * If the Citizen is currently unemployed, assigns the new job and updates 
 * the happiness meter accordingly, capping it at 100. Prints a message 
 * indicating the Citizen's new employment status.
 *
 * @param newJob A unique pointer to the new EmploymentStatus object.
 */
void Citizen::getHired(std::unique_ptr<EmploymentStatus> newJob)
{
    if (employmentStatus->getJobType() == "Unemployed")
    {
        employmentStatus = std::move(newJob);
        happinessMeter = std::min(happinessMeter + 10, 100); // Ensure it does not exceed 100
        std::cout << "Citizen got hired as " << employmentStatus->getJobType() << std::endl;
    }
}
/**
 * @brief Transitions the Citizen to an unemployed status when they are fired.
 *
 * If the Citizen is currently employed, this function resets their employment status 
 * to Unemployed and decreases their happiness meter by 20, ensuring it does not fall below 0.
 * Prints a message indicating the Citizen has been fired.
 */
void Citizen::getFired() {
    // Transition to Unemployed status
    if (employmentStatus->getJobType() != "Unemployed") {
        employmentStatus = make_unique<Unemployed>(); // Reset to unemployed status
        happinessMeter = std::max(happinessMeter - 20, 0); // Ensure it does not go below 0
        std::cout << "Citizen got fired and is now Unemployed." << std::endl;
    }
}

/**
 * @brief Assigns the Citizen to a specified building.
 *
 * This function assigns the Citizen to a building, represented by a shared pointer. 
 * If a valid building pointer is provided, the Citizen is added to the building's 
 * list of occupants.
 *
 * @param building A shared pointer to the Building object.
 */
void Citizen::assignToBuilding(std::shared_ptr<Building> building) {
    currentBuilding = building; // Assign the shared pointer
    if (currentBuilding) {
        currentBuilding->addCitizen(shared_from_this()); // Add citizen to building
    }
}

void Citizen::setHome(std::shared_ptr<Building> building) {
    home = building; // Assign the shared pointer
}

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
void Citizen::reactToEmergency(int damage) {
    if (damage <= 20) {
        happinessMeter -= 5;  // Minor happiness impact
    } else if (damage <= 50) {
        happinessMeter -= 15; // Medium happiness impact
    } else {
        happinessMeter -= 30; // Severe happiness impact
    }
    happinessMeter = std::max(happinessMeter, 0); // Keep happiness non-negative

    std::cout << "Citizen " << id << " happiness is now " << happinessMeter << std::endl;

    emotionalState->changeState(*this);
}

/**
 * @brief Sets a new employment status for the Citizen.
 *
 * This function changes the Citizen's employment status to a new value 
 * using move semantics to transfer ownership of the EmploymentStatus unique pointer.
 *
 * @param status A unique pointer to the new EmploymentStatus object.
 */
void Citizen::setEmploymentStatus(std::unique_ptr<EmploymentStatus> status) {
    employmentStatus = std::move(status); // Move the unique_ptr to the member
}

/**
 * @brief Retrieves the citizen's home.
 * 
 * This function returns a shared pointer to the `Building` instance representing the citizen's home.
 * The home is shared, so multiple entities can hold references to it.
 * 
 * @return std::shared_ptr<Building> A shared pointer to the Building instance representing the citizen's home.
 */
std::shared_ptr<Building> Citizen::getHome() {
    return home;
}

