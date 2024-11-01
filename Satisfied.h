#ifndef SATISFIED_H
#define SATISFIED_H

#include "EmotionalState.h"

class Satisfied : public EmotionalState {
public:
    // void react() const override;
    // void adjustHappiness(Citizen &citizen) override;
    void changeState(Citizen &citizen) override;
    string getCurrentEmotion() override;
};

#endif // SATISFIED_H
