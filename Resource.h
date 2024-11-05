#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <unordered_map>
#include <vector>

class Resource
{
protected:
    int capacity;

public:
    virtual ~Resource() = default;

    virtual int getCapacity() const = 0; // Pure virtual function
    virtual void refill(int amount) = 0; // Pure virtual function
    virtual int use(int amount) = 0;     // Pure virtual function
};

#endif