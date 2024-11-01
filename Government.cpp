#include "Government.h"

#include <vector>
#include <iostream>

Government::Government(string name)
    : cityName(std::move(name)),
      employmentRate(0.0),
      citybudget(0)
//   cityBuilder(std::make_unique<BuildingFactory>()),
//   strategy(std::make_unique<CategorizationStrategy>())
{
    populationNum = 0;
}

void Government::attach(CityGrowthObserver* ob)
{
    observers.push_back(ob);
}

void Government::detach(CityGrowthObserver* ob)
{
    observers.erase(std::remove(observers.begin(), observers.end(), ob), observers.end());
}

void Government::notifyObservers()
{
    for (CityGrowthObserver *observer : observers)
    {
        observer->update(this);
    }
}

void Government::setStrategy(CategorizationStrategy* str)
{
    strategy=str;
}

std::string Government::categorize()
{
    return strategy->categorize(this);
}

int Government::getPopulationNum()
{
    return populationNum;
}

double Government::getEmploymentRate()
{
    return employmentRate;
}

void Government::populationGrowth(std::shared_ptr<Citizen> citizen)
{
    population.push_back(citizen);
    populationNum++;
}

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

void Government::increaseInfurstructure()
{
    // if (cityBuilder) {
    //     infrastructure.push_back(cityBuilder->createBuilding());
    // }
      for (const auto &person : population)
    {
        if (person)
        {
           person->respondToIncreasedInfrastructure();
        }
    }
}

void Government::populationDecline(std::shared_ptr<Citizen> citizen)
{
    population.erase(remove(population.begin(), population.end(), citizen), population.end());
}

// marked
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

void Government::printInfo()
{
    std::cout << "=========================================" << std::endl;
    std::cout << "          City Information               " << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << " City Name       : " << cityName << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << " Population      : " << populationNum << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << " Employment Rate : " << std::fixed << std::setprecision(2)
              << (employmentRate * 100) << "%" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << " Satisfaction Rate : "<< std::fixed << std::setprecision(2) << populationSatisfactionRate() << "%"<<std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << " City Budget     : $" << citybudget << std::endl;
    std::cout << "=========================================" << std::endl;
}

double Government::populationSatisfactionRate()
{
    int satisfiedCount = 0;

    for (const auto &person : population)
    {
        if (person && person->getEmotionalState() == "Satisfied")
        {
            satisfiedCount++;
        }
    }
    if (population.empty()) return 0.0;

    // Calculate the satisfaction rate as a percentage
    return (static_cast<double>(satisfiedCount) / population.size()) * 100.0;
}


Government::~Government() = default;
