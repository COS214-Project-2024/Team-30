#include "Government.h"

Government::Government(string name)
{
    cityName = name;
    populationNum = 0;
    employmentRate = 0.0;
    citybudget = 0;
    coal = std::make_shared<Coal>(100);
    water = std::make_shared<Water>(200);
}

/**
 * @brief Adds a citizen to the population and assigns them a home.
 * @param citizen A shared pointer to the citizen being added.
 */
void Government::populationGrowth(std::shared_ptr<Citizen> citizen)
{
    if (citizen)

    {
        std::shared_ptr<Building> newplace = residentialFactory.createBuilding();
        citizen->setHome(newplace);
        infrastructure.push_back(newplace);
        population.push_back(citizen);
        populationNum++;
    }
}

/**
 * @brief Calculates the employment rate based on the population.
 */
void Government::calculateEmploymentRate()
{

    if (population.empty())
    {
        employmentRate = 0.0;
        return;
    }

    int employedCount = std::count_if(population.begin(), population.end(),
                                      [](const std::shared_ptr<Citizen> &citizen)
                                      {
                                          return citizen->getEmploymentStatus() != "Unemployed";
                                      });

    employmentRate = static_cast<double>(employedCount) / population.size();
}

/**
 * @brief Increases infrastructure if the budget allows.
 */
void Government::increaseInfurstructure()
{
    if (citybudget > 800)
    {
        for (int i = 0; i < 2; i++)
        {
            infrastructure.push_back(residentialFactory.createBuilding());
            infrastructure.push_back(commercialFactory.createBuilding());
            infrastructure.push_back(industrialFactory.createBuilding());
        }

        for (const auto &person : population)
        {
            if (person)
            {
                person->respondToIncreasedInfrastructure();
            }
        }

        citybudget = citybudget - 500;
    }

    else
    {
        cout << "The City doesnt have the budget for the expansion" << endl;
    }
}

/**
 * @brief function to calculate unemployment rate
 */
int Government::getNumberofUnemployedCitizens()
{
    int nmbr = 0;
    for (const auto &person : population)
    {
        if (person->getEmploymentStatus() == "Unemployed")
        {
            nmbr++;
        }
    }
    return nmbr;
}

/**
 * @brief helper function which is used for employment rate.
 * @return number as a int.
 */
int Government::getNumberOfEmployedCitizens()
{
    int nmbr = 0;
    for (const auto &person : population)
    {
        if (person->getEmploymentStatus() != "Unemployed")
        {
            nmbr++;
        }
    }
    return nmbr;
}

/**
 * @brief Print a summary for citizens.
 */
void Government::printCitizenSummary()
{
    if (populationNum == 0)
    {
        cout << "\n\n\n\n[WARNING] : City currently has no citizens\n\n\n"
             << endl;
        return;
    }
    std::cout << "============================================================" << std::endl;
    std::cout << "                     Citizens Summary                       " << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "            Population            : " << populationNum << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            Employed Citizens     : " << getNumberOfEmployedCitizens() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            Unemployed Citizens   : " << getNumberofUnemployedCitizens() << std::endl;
    std::cout << "============================================================" << std::endl;
}

/**
 * @brief Function for  citizen to get paid and become happier.
 */
void Government::payDay()
{
    for (const auto &person : population)
    {
        person->getPaid();
        person->respondToPayment();
    }
}

/**
 * @brief Function for provided job opportunities to citizens.
 */
void Government::jobOpportunities()
{
    // Initialize random number generators
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Probability that each unemployed person has to get hired (e.g., 50%)
    std::uniform_real_distribution<> hireChance(0.0, 1.0);
    const double hiringProbability = 0.4; // Adjust this value as needed

    // Create distribution for job types
    std::uniform_int_distribution<> jobDist(0, 1); // 0 = OfficeJob, 1 = IndustrialJob

    // Count unemployed people
    std::vector<Citizen *> unemployed;
    for (auto &person : population)
    {
        if (person->getEmploymentStatus() == "Unemployed")
        {
            unemployed.push_back(person.get());
        }
    }

    // Define a maximum number of hires allowed (e.g., 30% of unemployed)
    int maxHires = static_cast<int>(unemployed.size() * 1.0); // Adjust as needed
    int hiredCount = 0;

    // Attempt to hire unemployed citizens based on chance and max threshold
    for (auto &person : unemployed)
    {
        if (hiredCount >= maxHires)
            break; // Stop if max hires reached

        if (hireChance(gen) <= hiringProbability)
        {
            // Randomly assign job type
            std::unique_ptr<EmploymentStatus> newJob;
            if (jobDist(gen) == 0)
            {
                newJob = std::make_unique<OfficeJob>();
            }
            else
            {
                newJob = std::make_unique<IndustrialJob>();
            }

            // Hire person and increment the hired count
            person->getHired(std::move(newJob));
            hiredCount++;
        }
    }
    if (hiredCount == 0)
    {
        cout << "Nobody got hired :(" << endl;
        for (auto &person : unemployed)
        {
            person->reactToNotGettingHired();
        }
    }
}
/**
 * @brief Removes a citizen from the population based on their ID.
 * @param i The ID of the citizen to be removed.
 */
void Government::populationDecline(int i)
{

    std::shared_ptr<Citizen> citizen;
    for (const auto &person : population)
    {
        if (person->getID() == i)
        {
            citizen = person;
        }
    }

    if (citizen)
    {
        population.erase(remove(population.begin(), population.end(), citizen), population.end());
    }

    else
    {
        cout << " Could Not Find Person:" << i;
    }
}

/**
 * @brief Collects taxes from all citizens and updates the city budget.
 */
void Government::collectTaxes()
{
    for (const auto &person : population)
    {
        if (person)
        {
            citybudget += person->payTax();
            person->respondToTax();
        }
    }
}
/**
 * @brief Calculates the population satisfaction rate.
 * @return The satisfaction rate as a double between 0 and 1.
 */
double Government::populationSatisfactionRate()
{
    if (population.empty())
    {
        return 0.0;
    }
    int satisfiedCount = std::count_if(population.begin(), population.end(),
                                       [](const std::shared_ptr<Citizen> &citizen)
                                       {
                                           return citizen->getEmotionalState() == "Satisfied";
                                       });

    return static_cast<double>(satisfiedCount) / population.size();
}

/**
 * @brief Prints interface for the Game showing statistics for the city.
 */
void Government::printInfo()
{
    calculateEmploymentRate();
    std::cout << "============================================================" << std::endl;
    std::cout << "                     City Information                       " << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "            City Name       : " << cityName << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            Population      : " << populationNum << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            Employment Rate : " << std::fixed << std::setprecision(2)
              << (employmentRate * 100) << "%" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            Satisfaction Rate : " << std::fixed << std::setprecision(2) << populationSatisfactionRate() * 100 << "%" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            City Budget     : R" << citybudget << " k" << std::endl;
    std::cout << "============================================================" << std::endl;

    if (!population.empty())
    {
        std::cout << "============================================================" << std::endl;
        std::cout << "                     People Information                     " << std::endl;
        std::cout << "============================================================" << std::endl;
        for (const auto &person : population)
        {
            if (person)
            {
                person->printDetails();
            }
        }
    }

    if (!infrastructure.empty())
    {
        std::cout << "============================================================" << std::endl;
        std::cout << "                      Building Information                  " << std::endl;
        std::cout << "============================================================" << std::endl;
        for (const auto &building : infrastructure)
        {
            if (building)
            {
                building->displayInfo();
            }
        }
    }
}

/**
 * @brief Calculates the total residential capacity of all buildings.
 * @return The total residential capacity as an integer.
 */
int Government::ResidentialCapacity()
{
    int cap = 0;
    for (const auto &building : infrastructure)
    {
        if (building->getType() == "Residential Building")
        {
            cap += building->getCapacity();
        }
    }
    return cap;
}

/**
 * @brief Retrieves the current population of the city.
 * @return A vector of shared pointers to citizens.
 */
vector<std::shared_ptr<Citizen>> Government::getPeople()
{
    return population;
}

/**
 * @brief Retrieves the current infrastructure of the city.
 * @return A vector of shared pointers to buildings.
 */
vector<std::shared_ptr<Building>> Government::getInfrastructure()
{
    return infrastructure;
}
/**
 * @brief Default destructor for the Government class.
 */
Government::~Government() = default;
/**
 * @brief Attaches an observer to the city growth notifications.
 * @param ob A pointer to the observer to be added.
 */
void Government::attach(CityGrowthObserver *ob)
{
    observers.push_back(ob);
}
/**
 * @brief Detaches an observer from the city growth notifications.
 * @param ob A pointer to the observer to be removed.
 */
void Government::detach(CityGrowthObserver *ob)
{
    observers.erase(std::remove(observers.begin(), observers.end(), ob), observers.end());
}
/**
 * @brief Notifies all observers about changes in the city growth.
 */
void Government::notifyObservers()
{
    for (CityGrowthObserver *observer : observers)
    {
        observer->update(this);
    }
}
/**
 * @brief Sets the categorization strategy for the government.
 * @param str A pointer to the categorization strategy to be set.
 */
void Government::setStrategy(CategorizationStrategy *str)
{
    strategy = str;
}
/**
 * @brief Categorizes the city based on the current strategy.
 * @return A string representing the category.
 */
std::string Government::categorize()
{
    return strategy->categorize(this);
}
/**
 * @brief Retrieves the current population number.
 * @return The population number as an integer.
 */
int Government::getPopulationNum()
{
    return populationNum;
}
/**
 * @brief Retrieves the current employment rate.
 * @return The employment rate as a double.
 */
double Government::getEmploymentRate()
{
    return employmentRate;
}
/**
 * @brief Sets the city budget.
 * @param cityBudget The budget to be set.
 */
void Government::setCityBudget(int cityBudget)
{
    this->citybudget = cityBudget;
}
/**
 * @brief Retrieves the current city budget.
 * @return The city budget as an integer.
 */
int Government::getCityBudget()
{
    return citybudget;
}

void Government::distributeUtilities()
{
    for (auto &building : infrastructure)
    {
        // Check if building is valid before calling receiveUtilities
        if (building)
        {
            building->receiveUtilities(coal, water);
            auto &residents = building->getResidents();
            for (const auto &resident : residents)
            {
                resident->reactToUtilities(true);
            }
        }
    }
}