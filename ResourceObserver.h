#ifndef RESOURCE_OBSERVER_H
#define RESOURCE_OBSERVER_H
#include <string>
using namespace std;

class ResourceObserver
{   
    public: 
        virtual ~ResourceObserver() = default;
        virtual void update(const string& resourceName, int newCapacity) = 0;
        

};

#endif