#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

using namespace std;

class TrafficLights {
private:
    char state;
    int id;

public:
    void changeState();
    bool getState() const;
};

#endif // TRAFFICLIGHTS_H
