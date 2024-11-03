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
{       if(citybudget>800)
{
        for(int i =0; i<2; i++)
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
void Government::printCitizenSummary()
{
    if (populationNum == 0)
    {
        cout << "\n\n\n\n[WARNING] : City currently has no citizens\n\n\n"<<endl;
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

 void Government::payDay()
 {
    for (const auto &person : population)
    {
        person->getPaid();
        person->respondToPayment();
    }
    
 }

void Government::jobOpportunities()
{
    // Initialize random number generators
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    // Probability that each unemployed person has to get hired (e.g., 50%)
    std::uniform_real_distribution<> hireChance(0.0, 1.0);
    const double hiringProbability = 0.4;  // Adjust this value as needed
    
    // Create distribution for job types
    std::uniform_int_distribution<> jobDist(0, 1); // 0 = OfficeJob, 1 = IndustrialJob

    // Count unemployed people
    std::vector<Citizen*> unemployed;
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
        if (hiredCount >= maxHires) break; // Stop if max hires reached

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
        cout << "Nobody got hired :("<<endl;
        for (auto &person : unemployed)
        {
            person->reactToNotGettingHired();
        }
        
    }
}

void Government::populationDecline(int i)
{

std::shared_ptr<Citizen> citizen;
   for (const auto &person : population)
    {
        if (person->getID()== i)
        {
          citizen = person;
        }
    }

if(citizen)
{
    population.erase(remove(population.begin(), population.end(), citizen), population.end());

}

else
{
    cout<< " Could Not Find Person:" << i;
}
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

int Government::ResidentialCapacity(){
    int cap=0;
    for (const auto &building : infrastructure)
    {
        if (building->getType() == "Residential Building")
        {
            cap += building->getCapacity();
        }
    }
    return cap;
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
void Government::setCityBudget(int cityBudget)
{
    this->citybudget = cityBudget;
}
int Government::getCityBudget()
{
    return citybudget;
}