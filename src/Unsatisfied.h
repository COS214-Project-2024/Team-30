#ifndef UNSATISFIED_H
#define UNSATISFIED_H

#include "EmotionalState.h"


class Unsatisfied : public EmotionalState {
public:
    // void react() const override;
    // void adjustHappiness(Citizen &citizen) override;
    void changeState(Citizen &citizen) override;
    string getCurrentEmotion() override;
};

#endif // UNSATISFIED_H
