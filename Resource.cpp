#include "Resource.h"

Resource::Resource(int capacity)
:capacity(capacity)
{
}

bool Resource::isCritical() const
{
    return capacity < 50;
}
