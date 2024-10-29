#include "Government.h"

Government::Government(string name)
    : cityName(std::move(name)),
      employmentRate(0.0),
      citybudget(0),
    //   cityBuilder(std::make_unique<BuildingFactory>()),        
      strategy(std::make_unique<CategorizationStrategy>()) {    
}


void Government::attach(std::shared_ptr<CityGrowthObserver> ob) {
        observers.push_back(ob);
    }


void Government::detach(std::shared_ptr<CityGrowthObserver> ob) {
    observers.erase(std::remove(observers.begin(), observers.end(), ob), observers.end());
}

 void Government::notifyObservers() {
 }

 void Government::populationGrowth(std::shared_ptr<Citizen> citizen) {
        population.push_back(citizen);
        populationNum++;

    }


void Government::calculateEmploymentRate() {
    
    if (population.empty()) {
        employmentRate = 0.0;
        return;
    }

    int employedCount = std::count_if(population.begin(), population.end(),
                                      [](const std::shared_ptr<Citizen>& citizen) {
                                          return citizen->getEmploymentStatus() != "Unemployed";
                                      });

    employmentRate = static_cast<double>(employedCount) / population.size();
}

    void Government::increaseInfurstructure() {
        // if (cityBuilder) {
        //     infrastructure.push_back(cityBuilder->createBuilding());
        // }
    }

   
    void Government::populationDecline(std::shared_ptr<Citizen> citizen) {
        population.erase(remove(population.begin(), population.end(), citizen), population.end());
    }

    
    void Government::collectTaxes() {
         for (const auto& person : population) {
            if (person)
            {
                citybudget += person->payTax();
            } 
        }
    }

    void Government::printInfo()  {
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
    std::cout << " City Budget     : $" << citybudget << std::endl;
    std::cout << "=========================================" << std::endl;
}

    
   Government:: ~Government() = default;
    


