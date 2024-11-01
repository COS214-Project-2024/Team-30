#include "Citizen.h"
#include "Building.h"
#include <iomanip>
int Citizen::nextID = 1; // or 0, depending on your starting point for IDs

Citizen::Citizen() : id(nextID++)
{
    accountBalance = 0;
    // Random number generator setup
    random_device rd;
    mt19937 gen(rd());

    // Step 1: Randomly assign EmploymentStatus
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

    // Step 2: assign initial EmotionalState
    emotionalState = make_unique<Satisfied>();

    // Step 3: Randomly assign initial happiness meter
    uniform_int_distribution<> happinessDist(0, 100); // Adjust the range as necessary
    happinessMeter = happinessDist(gen); // Assign a random happiness level

    emotionalState->changeState(*this);
    
    // Initialize other attributes
    income = employmentStatus->getIncome(); // Default income, modify if needed
    getPaid(); // Presumably fills account balance based on income
}
void Citizen::getPaid()
{
    accountBalance = accountBalance + income;
}
int Citizen::getID() const
{
    return id;
}
int Citizen::getHappinessMeter()
{
    return happinessMeter;
}
void Citizen::setEmotionalState(unique_ptr<EmotionalState> emotionalState)
{
    this->emotionalState = std::move(emotionalState);
}
int Citizen::getIncome()
{
    return income;
}
int Citizen::getAccountBalance()
{
    return this->accountBalance;
}

void Citizen::payTaxes()
{
    accountBalance = accountBalance - taxBracket->getamountToPay(income);
}

void Citizen::printDetails()
{
    // Set a width for the labels
    int labelWidth = 20;

    // Calculate the length of the border based on the maximum line length
    std::string border(60, '*'); // Adjust the number (60) based on desired border length

    std::cout << border << std::endl;  // Print top border

    std::cout << std::setw(labelWidth) << std::left << "Person:" 
              << getID() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Employment Status:" 
              << employmentStatus->getJobType() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Income:" 
              << income << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Emotional State:" 
              << emotionalState->getEmotionalState() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Tax Bracket:" 
              << taxBracket->getTaxBracket() << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Account Balance:" 
              << accountBalance << std::endl;

    std::cout << std::setw(labelWidth) << std::left << "Happiness Meter:" 
              << happinessMeter << std::endl;

    std::cout << border << std::endl;  // Print bottom border
}

// logic for paying taxes
int Citizen::payTax()
{
    // get that person current tax bracket

    int amount = taxBracket->getamountToPay(income);

    if (amount > income)
    {
        amount = income; // if they dont have enough to pay taxes
    }

    income = income - amount;
    return amount; // added to city budget
}

// this is for employment rate
string Citizen::getEmploymentStatus()
{
    return employmentStatus->getJobType();
}

string Citizen::getEmotionalState()
{
    return emotionalState->getEmotionalState();
}

void Citizen::respondToTax()
{
    int penalty = (employmentStatus->getJobType() == "Unemployed") ? 15 : 10;
    happinessMeter -= penalty;                    // A tax penalty greater for unemployed citizens
    happinessMeter = std::max(happinessMeter, 0); // Ensure it doesn't go below 0
    emotionalState->changeState(*this);           // Trigger state change if necessary
}

void Citizen::respondToPayment()
{
    happinessMeter += 20;                           // Increase happiness with payment
    happinessMeter = std::min(happinessMeter, 100); // Ensure it doesn't exceed 100
    emotionalState->changeState(*this);
}

int clamp(const int &value, const int &min, const int &max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}
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
void Citizen::respondToIncreasedInfrastructure()
{
    happinessMeter += 5;                           // Increase happiness with payment
    happinessMeter = std::min(happinessMeter, 100); // Ensure it doesn't exceed 100
    emotionalState->changeState(*this);
}

void Citizen::getHired(std::unique_ptr<EmploymentStatus> newJob) {
    if (employmentStatus->getJobType() == "Unemployed") {
        employmentStatus = std::move(newJob);
        // Increase happiness meter or take any action needed
        happinessMeter = std::min(happinessMeter + 10, 100); // Ensure it does not exceed 100
        cout << "Citizen got hired as " << employmentStatus->getJobType() << endl;
    }
}

void Citizen::getFired() {
    // Transition to Unemployed status
    if (employmentStatus->getJobType() != "Unemployed") {
        employmentStatus = make_unique<Unemployed>(); // Reset to unemployed status
        // Decrease happiness meter or take any action needed
        happinessMeter = std::max(happinessMeter - 20, 0); // Ensure it does not go below 0
        cout << "Citizen got fired and is now Unemployed." << endl;
    }
}

void Citizen::assignToBuilding(std::shared_ptr<Building> building) {
    currentBuilding = building; // Assign the shared pointer
    if (currentBuilding) {
        currentBuilding->addCitizen(shared_from_this()); // Add citizen to building
    }
}

void Citizen::reactToEmergency(int damage) {
    if (damage <= 20) {
        happinessMeter -= 5;  // Minor happiness impact
    } else if (damage <= 50) {
        happinessMeter -= 15; // Medium happiness impact
    } else {
        happinessMeter -= 30; // Severe happiness impact
    }
    happinessMeter = max(happinessMeter, 0); // Keep happiness non-negative

    cout << "Citizen " << id << " happiness is now " << happinessMeter << endl;

    emotionalState->changeState(*this);
}

 void Citizen::setEmploymentStatus(std::unique_ptr<EmploymentStatus> status) {
        employmentStatus = std::move(status); // Move the unique_ptr to the member
    }
