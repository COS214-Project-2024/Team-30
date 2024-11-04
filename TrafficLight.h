#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

using namespace std;

class TrafficLight {
private:
    char state;
    static int numLights;
protected:
    int id;
public:
    TrafficLight();
    void changeState();
    char getState() const;
    int getID() const;
    bool operator==(const TrafficLight& other) const {
        return this->id == other.id;
    }
    void setState(char c)
    {
        state = c;
    }

};

#endif // TRAFFICLIGHTS_H
