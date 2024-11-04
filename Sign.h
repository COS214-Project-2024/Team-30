#ifndef SIGN_H
#define SIGN_H

#include <string>

using namespace std;

class Sign {
protected:
    string message;
    string type;
    static int numSigns;
    int ID;
public:
    Sign(const string& message);
    virtual ~Sign() = default;
    int getID() const;
    string getMessage() const;
    string getType() const;
    bool operator==(const Sign& other) const {
        return this->ID == other.ID;
    }
};

#endif // SIGN_H
