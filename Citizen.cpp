#include "Citizen.h"

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

    // Step 2: Randomly assign initial EmotionalState
    uniform_int_distribution<> emotionDist(0, 1);
    int emotionChoice = emotionDist(gen);

    if (emotionChoice == 0)
    {
        emotionalState = make_unique<Satisfied>();
    }
    else
    {
        emotionalState = make_unique<Unsatisfied>();
    }

    // Step 3: Initialize other attributes
    income = employmentStatus->getIncome(); // Default income, modify if needed
    getPaid();
    happinessMeter = 50; // Default happiness, adjust as needed
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
    cout << "Person:\t" << getID() << endl;
    cout << "Employment Status:\t" << employmentStatus->getJobType() << endl;
    cout << "Income:\t" << income << endl;
    cout << "Emotional State:\t" << emotionalState->getEmotionalState() << endl;
    cout << "Tax Bracket:\t" << taxBracket->getTaxBracket() << endl;
    cout << "Account Balance:\t" << accountBalance << endl;
    cout << "Happiness Meter:\t" << happinessMeter << endl;
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