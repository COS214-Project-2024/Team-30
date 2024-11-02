#ifndef SIGN_H
#define SIGN_H

#include <string>

using namespace std;

class Sign {
protected:
    string message;
    string type;

public:
    Sign(string message, string type);
    virtual ~Sign() = default;
    virtual void signIt(string message, string type);
};

#endif // SIGN_H
