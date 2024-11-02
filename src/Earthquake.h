#include "Emergencies.h"

class Earthquake : public Emergencies {
public:
    void accessDamage(shared_ptr<Building> buildingType) override;
    string getTypeOfEmergency() override;
   
};
