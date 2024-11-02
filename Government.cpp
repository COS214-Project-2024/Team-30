#include "Government.h"

Government::Government(string name)
{
    cityName = name;
    populationNum = 0;
    employmentRate= 0.0;
    citybudget = 0;
}

void Government::populationGrowth(std::shared_ptr<Citizen> citizen)
{ if( citizen)

{   std::shared_ptr<Building> newplace= residentialFactory.createBuilding();
    citizen->setHome(newplace);
    infrastructure.push_back(newplace);
    population.push_back(citizen);
    populationNum++;
}
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
{       if(citybudget>500)
{
        for(int i =0; i<5; i++)
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

    citybudget = citybudget -500;
} 

else
{
    cout<<"The City doesnt have the budget for the expansion"<<endl;
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

void Government::printInfo()
{   calculateEmploymentRate();
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
    std::cout << "            Satisfaction Rate : "<< std::fixed << std::setprecision(2) << populationSatisfactionRate() * 100<< "%"<<std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "            City Budget     : R" << citybudget << " k"<< std::endl;
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
    std::cout << "                      City Information                      " << std::endl;
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

vector<std::shared_ptr<Citizen>> Government::getPeople ()
{
    return population;
}


vector<std::shared_ptr<Building>> Government::getInfrastructure()
{
    return infrastructure;
}



Government::~Government() = default;

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