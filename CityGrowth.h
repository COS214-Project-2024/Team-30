#ifndef CITYGROWTH_H
#define CITYGROWTH_H

class CityGrowthObserver{
    public:
        virtual void update(int population) = 0;
};

class Housing : public CityGrowthObserver {
public:
    void update(int population) override;
};

class Economy : public CityGrowthObserver {
public:
    void update(int population) override;
};

class Infrastructure : public CityGrowthObserver {
public:
    void update(int population) override;
};

#endif