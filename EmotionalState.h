#ifndef EMOTIONALSTATE_H
#define EMOTIONALSTATE_H

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Citizen;  // Forward declaration

class EmotionalState {
public:
    virtual void changeState(Citizen &citizen) = 0;  // Pure virtual function
    virtual string getEmotionalState() = 0;  // Pure virtual function
    virtual ~EmotionalState() {}
};

#endif // EMOTIONALSTATE_H
